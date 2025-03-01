/*

Copyright (c) 2003 - 2005
Other World Computing
All rights reserved

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer as the first lines of
   each file.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.

3. Redistributions in binary form must retain unchanged the elements of the application 
   which credit Other World Computing (such as the splash screen and the "about box").

4. Redistributions in binary form must not require payment (or be bundled with items 
   requiring payment).

This software is provided by Other World Computing ``as is'' and any express or implied
warranties, including, but not limited to, the implied warranties of
merchantability and fitness for a particular purpose are disclaimed. In no event
shall Ryan Rempel or Other World Computing be liable for any direct, indirect,
incidental, special, exemplary, or consequential damages (including, but not
limited to, procurement of substitute goods or services; loss of use, data, or
profits; or business interruption) however caused and on any theory of
liability, whether in contract, strict liability, or tort (including negligence
or otherwise) arising in any way out of the use of this software, even if
advised of the possibility of such damage.

*/


#include "XPFVolumeDisplay.h"
#include "XPFApplication.h"
#include "XPFStrings.h"

#include "MountedVolume.h"
#include "XPFVersion.h"
#include "XPFPrefs.h"
#include "XPostFacto.h"
#include "XPFLog.h"
#include "XPFIODevice.h"
#include "XPFVolumeList.h"
#include "XPFVolumeInspectorWindow.h"

#include "UStaticText.h"
#include "UThemeEnvironment.h"

//========================================================================================
// CLASS XPFVolumeDisplay
//========================================================================================

MA_DEFINE_CLASS(XPFVolumeDisplay);

#define Inherited TView

XPFVolumeDisplay::~XPFVolumeDisplay()
{
	ReleaseIconRef (fIconRef);
}

TDrawingEnvironment* 
XPFVolumeDisplay::DoMakeNewDrawingEnvironment()
{
	return new TThemeWhiteEnvironment;
}

void 
XPFVolumeDisplay::DoHighlightSelection (HLState fromHL, HLState toHL)
{
	if (Focus () && (fromHL != toHL)) {
		CRect_AC pixels (GetQDExtent ());
		SetupDrawingEnvironment();
		::PenNormal();
		UseSelectionColor ();

		::EraseRect (pixels);

		switch (toHL) {
			case hlOn:
				::PenMode (patCopy | hilite);
				::PaintRect (pixels);
				break;
				
			case hlDim:
				::PenMode (patCopy | hilite);
				::FrameRect (pixels);
				break;
		}
		
		// Now, force the subviews to redraw, since I've just erased their work!
		
		for (CSubViewIterator iter (this); iter; ++iter) iter->HandleDraw (iter->GetExtent ());		
	}
}

void 
XPFVolumeDisplay::DoPostCreate(TDocument* itsDocument)
{
	Inherited::DoPostCreate (itsDocument);
	
	fApp = (XPFApplication *) gApplication;
	fApp->AddDependent (this);
	fPrefs = (XPFPrefs *) GetDocument ();
	fPrefs->AddDependent (this);
	fSelected = false;
	
	fVolumeName = (TStaticText *) this->FindSubView ('voln');
	fIcon = (TIcon *) this->FindSubView ('icon');
	fStatus = (TStaticText *) this->FindSubView ('vols');
	
	fWarningIcon = (XPFWarningIcon *) this->FindSubView ('warn');
}

void 
XPFVolumeDisplay::DoEvent (EventNumber eventNumber, TEventHandler* source, TEvent* event)
{
	Inherited::DoEvent (eventNumber, source, event);

	if ((eventNumber == mIconHit) && (source == fWarningIcon)) {
		XPFVolumeInspectorWindow::ShowInspectorForVolume (fVolume);
	}	
}

void 
XPFVolumeDisplay::setVolume (MountedVolume* newVolume)
{
	OSErr err;
	FSSpec volSpec;
	IconFamilyHandle familyHandle;
	IconSuiteRef iconSuite;
	
	fVolume = newVolume;
	fVolume->AddDependent (this);
	fVolumeName->SetText (fVolume->getVolumeName (), true);
	
	err = FSGetCatalogInfo (fVolume->getRootDirectory (), kFSCatInfoNone, NULL, NULL, &volSpec, NULL);
	err = GetIconRefFromFile (&volSpec, &fIconRef, NULL);
	err = IconRefToIconFamily (fIconRef, kSelectorAllAvailableData, &familyHandle);
	err = IconFamilyToIconSuite (familyHandle, kSelectorAllAvailableData, &iconSuite);
	
	fIcon->SetIconSuite (iconSuite, true);
	
	DoUpdate (cSetRebootInMacOS9, fPrefs, NULL, NULL);
	DoUpdate (cSetMacOS9Disk, fPrefs, fPrefs->getMacOS9Disk (), NULL);
	DoUpdate (cSetTargetDisk, fPrefs, fPrefs->getTargetDisk (), NULL);
	DoUpdate (cSetInstallCD, fPrefs, fPrefs->getInstallCD (), NULL);
	DoUpdate (cSetSymlinkStatus, fVolume, fVolume, NULL);
	DoUpdate (cSetExtensionsCacheStatus, fVolume, fVolume, NULL);
}

void
XPFVolumeDisplay::DoUpdate	(ChangeID_AC theChange, 
							MDependable_AC* changedObject,
							void* changeData,
							CDependencySpace_AC* dependencySpace)
{
	MountedVolume *vol = (MountedVolume *) changeData;

	switch (theChange) {
	
		case cSetRebootInMacOS9:
			updateStatusText ();
			updateActiveState ();
			break;
				
		case cSetVolumeName:
			fVolumeName->SetText (fVolume->getVolumeName (), true);
			break;
			
		case cDeleteMountedVolume:
			if (fVolume == vol) {
				TView *nextView = this;
				while ((nextView = nextView->GetNextView ())) {
					CViewPoint newLoc (nextView->GetLocation ());
					newLoc.v -= GetSize().v;
					nextView->Locate (newLoc, true);
				}
				delete this;
			}
			break;
			
		case cSetSelectedVolume:
			if (fVolume == vol) {
				fSelected = true;
				AddAdorner (&TAdorner::fgSelectionAdorner, kAdornLast, true);
				ScrollSelectionIntoView (kRedraw);
			} else {
				fSelected = false;
				DeleteAdorner (&TAdorner::fgSelectionAdorner, true);
			}	
			break;
			
		case cSetInstallCD:
			updateActiveState ();
			break;
				
		default:
			if (fVolume == vol) updateActiveState ();
			Inherited::DoUpdate (theChange, changedObject, changeData, dependencySpace);
			break;
	}
}

void
XPFVolumeDisplay::updateActiveState ()
{
	unsigned bootStatus = fVolume->getBootStatus ();
	unsigned targetStatus = fVolume->getInstallTargetStatus ();
	unsigned installerStatus = fVolume->getInstallerStatus ();
	short bootWarnings[20];
	short bootNotes[10];

	if (fPrefs->getRebootInMacOS9 ()) {
		SetActiveState (fVolume->getMacOS9BootStatus() == kStatusOK, false);
		fWarningIcon->Show (false, true);
	} else {
		if (fPrefs->getInstallCD ()) {
			SetActiveState ((installerStatus == kStatusOK) || (bootStatus == kStatusOK) || (targetStatus == kStatusOK), false);
			fVolume->getBootWarnings (true, bootWarnings, bootNotes);
		} else {
			SetActiveState ((installerStatus == kStatusOK) || (bootStatus == kStatusOK), false);
			fVolume->getBootWarnings (false, bootWarnings, bootNotes);
		}
		if (bootWarnings[0] || bootNotes[0]) {
			fWarningIcon->SetSystemIcon(bootWarnings[0] ? kAlertCautionIcon : kAlertNoteIcon);
			fWarningIcon->Show (true, true);
		}
		else {
			fWarningIcon->Show (false, true);
		}
	}	
}

void
XPFVolumeDisplay::updateStatusText ()
{
	unsigned statusCode;
	if (fPrefs->getRebootInMacOS9 ()) {
		statusCode = fVolume->getMacOS9BootStatus ();
	} else if (fVolume->getHasInstaller ()) {
		statusCode = fVolume->getInstallerStatus ();
	} else {
		statusCode = fVolume->getBootStatus ();	
	}
	
	CStr255_AC status;
	if (statusCode == kStatusOK) {
		if (fPrefs->getRebootInMacOS9 ()) {
			status = "Mac OS 9.x";	// FIXME -- it would be nice to get the actual version
		} else if (fVolume->getHasMachKernel ()) {
			status = fVolume->getIsDarwin () ? "Darwin " : "Mac OS X ";
			status += fVolume->getMacOSXVersion ();
			if (fVolume->getHasInstaller ()) status += " Install CD";
		}
	} else {
		status.CopyFrom (kXPFStringsResource, statusCode, 255);
	}
	
	fStatus->SetText (status, true);
}
