/*

Copyright (c) 2003
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

3. Redistributions in binary form must retain the link to Other World
   Computing's web site in the application's "About Box."

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

#include "XPFRestartCommand.h"

#include "MountedVolume.h"
#include "XPFPrefs.h"
#include "NVRAM.h"
#include "FSRefCopying.h"
#include "XPFLog.h"
#include "XPFApplication.h"
#include "XPFErrors.h"
#include "stdio.h"
#include "XPFProgressWindow.h"
#include "XPFStrings.h"
#include "XPFAuthorization.h"
#include "XPFFSRef.h"

#define Inherited TCommand

XPFRestartCommand::XPFRestartCommand (XPFPrefs *prefs, bool restartNow)
	: fPrefs (prefs), fRestartNow (restartNow)
{
}

void
XPFRestartCommand::tellFinderToRestart ()
{
	if (((XPFApplication *) gApplication)->getDebugOptions () & kDisableRestart) return;

	AEDesc finderAddr;
	AppleEvent myRestart, nilReply;
	AEEventClass eventClass;

#ifdef __MACH__
	eventClass = kCoreEventClass;
	ProcessSerialNumber psn = {0, kSystemProcess};
	ThrowIfOSErr_AC (AECreateDesc (typeProcessSerialNumber, &psn, sizeof (psn), &finderAddr));
#else
	eventClass = kAEFinderEvents;
	OSType fndrSig = 'MACS';
    ThrowIfOSErr_AC (AECreateDesc (typeApplSignature, &fndrSig, sizeof(fndrSig), &finderAddr));
#endif

   	ThrowIfOSErr_AC (AECreateAppleEvent (eventClass, kAERestart, &finderAddr, kAutoGenerateReturnID,
                              kAnyTransactionID, &myRestart));
    ThrowIfOSErr_AC (AESend (&myRestart, &nilReply, kAENoReply + kAECanSwitchLayer + kAEAlwaysInteract,
                  kAENormalPriority, kAEDefaultTimeout, NULL, NULL));
	AEDisposeDesc (&myRestart);
	AEDisposeDesc (&finderAddr);
}

void 
XPFRestartCommand::DoIt ()
{
	fPrefs->writePrefsToNVRAM (getInstalling ());
	if (fRestartNow) tellFinderToRestart ();
}
