/*
	File:		TradDriverLoaderLib.h

	Contains:	C interface for the pseudo-DriverLoaderLib for 'DRVR's.

	Written by:	Quinn

	Copyright:	Copyright (c) 1996-2001 by Apple Computer, Inc., All Rights Reserved.

	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.
				("Apple") in consideration of your agreement to the following terms, and your
				use, installation, modification or redistribution of this Apple software
				constitutes acceptance of these terms.  If you do not agree with these terms,
				please do not use, install, modify or redistribute this Apple software.

				In consideration of your agreement to abide by the following terms, and subject
				to these terms, Apple grants you a personal, non-exclusive license, under Apple�s
				copyrights in this original Apple software (the "Apple Software"), to use,
				reproduce, modify and redistribute the Apple Software, with or without
				modifications, in source and/or binary forms; provided that if you redistribute
				the Apple Software in its entirety and without modifications, you must retain
				this notice and the following text and disclaimers in all such redistributions of
				the Apple Software.  Neither the name, trademarks, service marks or logos of
				Apple Computer, Inc. may be used to endorse or promote products derived from the
				Apple Software without specific prior written permission from Apple.  Except as
				expressly stated in this notice, no other rights or licenses, express or implied,
				are granted by Apple herein, including but not limited to any patent rights that
				may be infringed by your derivative works or by other works in which the Apple
				Software may be incorporated.

				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
				WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
				WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
				PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
				COMBINATION WITH YOUR PRODUCTS.

				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
				CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
				GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
				ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
				OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
				(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
				ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Change History (most recent first):

$Log$
Revision 1.2  2003/01/05 22:32:19  ryan
Fixed the line endings :-)

/*
	File:		TradDriverLoaderLib.h

	Contains:	C interface for the pseudo-DriverLoaderLib for 'DRVR's.

	Written by:	Quinn

	Copyright:	Copyright (c) 1996-2001 by Apple Computer, Inc., All Rights Reserved.

	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.
				("Apple") in consideration of your agreement to the following terms, and your
				use, installation, modification or redistribution of this Apple software
				constitutes acceptance of these terms.  If you do not agree with these terms,
				please do not use, install, modify or redistribute this Apple software.

				In consideration of your agreement to abide by the following terms, and subject
				to these terms, Apple grants you a personal, non-exclusive license, under Apple�s
				copyrights in this original Apple software (the "Apple Software"), to use,
				reproduce, modify and redistribute the Apple Software, with or without
				modifications, in source and/or binary forms; provided that if you redistribute
				the Apple Software in its entirety and without modifications, you must retain
				this notice and the following text and disclaimers in all such redistributions of
				the Apple Software.  Neither the name, trademarks, service marks or logos of
				Apple Computer, Inc. may be used to endorse or promote products derived from the
				Apple Software without specific prior written permission from Apple.  Except as
				expressly stated in this notice, no other rights or licenses, express or implied,
				are granted by Apple herein, including but not limited to any patent rights that
				may be infringed by your derivative works or by other works in which the Apple
				Software may be incorporated.

				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
				WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
				WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
				PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
				COMBINATION WITH YOUR PRODUCTS.

				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
				CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
				GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
				ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
				OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
				(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
				ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Change History (most recent first):

Revision 1.1  2003/01/05 20:58:02  ryan
/*
	File:		TradDriverLoaderLib.h

	Contains:	C interface for the pseudo-DriverLoaderLib for 'DRVR's.

	Written by:	Quinn

	Copyright:	Copyright (c) 1996-2001 by Apple Computer, Inc., All Rights Reserved.

	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.
				("Apple") in consideration of your agreement to the following terms, and your
				use, installation, modification or redistribution of this Apple software
				constitutes acceptance of these terms.  If you do not agree with these terms,
				please do not use, install, modify or redistribute this Apple software.

				In consideration of your agreement to abide by the following terms, and subject
				to these terms, Apple grants you a personal, non-exclusive license, under Apple�s
				copyrights in this original Apple software (the "Apple Software"), to use,
				reproduce, modify and redistribute the Apple Software, with or without
				modifications, in source and/or binary forms; provided that if you redistribute
				the Apple Software in its entirety and without modifications, you must retain
				this notice and the following text and disclaimers in all such redistributions of
				the Apple Software.  Neither the name, trademarks, service marks or logos of
				Apple Computer, Inc. may be used to endorse or promote products derived from the
				Apple Software without specific prior written permission from Apple.  Except as
				expressly stated in this notice, no other rights or licenses, express or implied,
				are granted by Apple herein, including but not limited to any patent rights that
				may be infringed by your derivative works or by other works in which the Apple
				Software may be incorporated.

				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
				WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
				WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
				PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
				COMBINATION WITH YOUR PRODUCTS.

				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
				CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
				GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
				ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
				OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
				(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
				ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Change History (most recent first):

Initial check-in. For getting partition numbers of Firewire volumes.
/*
	File:		TradDriverLoaderLib.h

	Contains:	C interface for the pseudo-DriverLoaderLib for 'DRVR's.

	Written by:	Quinn

	Copyright:	Copyright (c) 1996-2001 by Apple Computer, Inc., All Rights Reserved.

	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.
				("Apple") in consideration of your agreement to the following terms, and your
				use, installation, modification or redistribution of this Apple software
				constitutes acceptance of these terms.  If you do not agree with these terms,
				please do not use, install, modify or redistribute this Apple software.

				In consideration of your agreement to abide by the following terms, and subject
				to these terms, Apple grants you a personal, non-exclusive license, under Apple�s
				copyrights in this original Apple software (the "Apple Software"), to use,
				reproduce, modify and redistribute the Apple Software, with or without
				modifications, in source and/or binary forms; provided that if you redistribute
				the Apple Software in its entirety and without modifications, you must retain
				this notice and the following text and disclaimers in all such redistributions of
				the Apple Software.  Neither the name, trademarks, service marks or logos of
				Apple Computer, Inc. may be used to endorse or promote products derived from the
				Apple Software without specific prior written permission from Apple.  Except as
				expressly stated in this notice, no other rights or licenses, express or implied,
				are granted by Apple herein, including but not limited to any patent rights that
				may be infringed by your derivative works or by other works in which the Apple
				Software may be incorporated.

				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
				WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
				WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
				PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
				COMBINATION WITH YOUR PRODUCTS.

				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
				CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
				GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
				ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
				OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
				(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
				ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Change History (most recent first):


Revision 1.3  2001/11/07 15:58:57  eskimo1
Tidy up headers, add CVS logs, update copyright.


         <2>     21/9/01    Quinn   Changes for CWPro7 Mach-O build.
         <1>     25/2/99    Quinn   First checked in.
*/

#pragma once

/////////////////////////////////////////////////////////////////
// MoreIsBetter Setup

#include "MoreSetup.h"

/////////////////////////////////////////////////////////////////
// Mac OS Interfaces

#if ! MORE_FRAMEWORK_INCLUDES
	#include <MacTypes.h>
	#include <Devices.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

// The following routines are implemented with semantics virtually identical
//  to those found in DriverLoaderLib.  You should look in
//  "Designing PCI Cards and Drivers for Power Macintosh Computers" for
//  documentation.  You can FTP an electronic copy from:
//  <http://developer.apple.com/macos/opentransport/docs/dev/Designing_PCI_Cards_Drivers.pdf>

extern pascal SInt16 TradHigherDriverVersion(NumVersion *dv1, NumVersion *dv2);

extern pascal UnitNumber TradHighestUnitNumber(void);

extern pascal OSErr TradDriverGestaltOn(DriverRefNum refNum);

extern pascal OSErr TradDriverGestaltOff(DriverRefNum refNum);

extern pascal Boolean TradDriverGestaltIsOn(DriverFlags flags);

extern pascal OSErr TradLookupDrivers(UnitNumber beginningUnit,
										UnitNumber endingUnit,
										Boolean emptyUnits,
										ItemCount *returnedRefNums, 
										DriverRefNum *refNums);

///////////////////////////////////////////////////////////////////////////

// The following routines are similar to the corresponding routines in
//  DriverLoaderLib, but their interface differs because of the
//  inherent differences between 'DRVR's and 'ndrv's.  The comments
//  cover the differences for each routine.  If there's a difference
//  that's not commented, it's most probably a bug and you should let
//  me know.

extern pascal OSErr TradInstallDriverFromPtr(DRVRHeaderPtr driver,
												UnitNumber beginningUnit,
												UnitNumber endingUnit,
												DriverRefNum *refNum);
	// This routine is similar to InstallDriverFromMemory except
	//  that you pass a pointer to the 'DRVR', rather than a base pointer
	//  and length.  This pointer is copied verbatim into the dCtlDriver
	//  field of the DCE, so you have to make sure that it's in
	//  the system heap if the driver is going to hang around longer than
	//  your application.
	// One other deviation from InstallDriverFromMemory is that this
	//  call won't replace an existing driver.  This is because 'DRVR's
	//  don't have infrastructure to support this.  If there's already
	//  a driver of the same name in the unit table, the call will fail
	//  with a dupFNErr, and *refNum will be set to the refnum of the
	//  existing driver.
	// The semantics of the endingUnit match those of DriverLoaderLib,
	//  ie the call will not grow the unit table unless endingUnit is
	//  greater than TradHighestUnitNumber.  The simplest way to work
	//  this is to pass TradHighestUnitNumber() + 1 to endingUnit.
	// If the call fails, it's your responsibility to dispose of the
	//  the driver pointer.  If it succeeds, the system has a copy
	//  of the pointer, which can be disposed by calling TradRemoveDriver.

extern pascal OSErr TradInstallDriverFromHandle(DRVRHeaderHandle driver,
												UnitNumber beginningUnit,
												UnitNumber endingUnit,
												DriverRefNum *refNum);
	// This routine is similar to InstallDriverFromMemory except
	//  that you pass a handle to the 'DRVR', rather than a base pointer
	//  and length.  This is generally more convenient in the traditional
	//  'DRVR' world.
	// In most other respects, this routine works like TradInstallDriverFromPtr.
	//  The routine simply creates a pointer in the system heap and copies
	//  your driver into it, then calls TradInstallDriverFromPtr.  Because
	//  a copy is made, you do not have to ensure that the handle you
	//  pass in is in the system heap.
	// Regardless of whether call succeeds or fails, it's your responsibility
	//  to dispose of the driver handle.
	
extern pascal OSErr TradInstallDriverFromResource(SInt16 rsrcID, StringPtr rsrcName,
												UnitNumber beginningUnit,
												UnitNumber endingUnit,
												DriverRefNum *refNum);
	// This call offers functionality like InstallDriverFromFile.
	//  It differs from InstallDriverFromFile in that the driver is expected
	//  to be in a resource in the current resource file.  If rsrcName is nil,
	//  the call uses Get1Resource('DRVR', rsrcID) to get the driver.  If
	//  rsrcName is not nil, it uses Get1NamedResource('DRVR', rsrcName)
	//  to get the driver.
	// In most other respects, this routine works like TradInstallDriverFromPtr.
	// If the call fails, the routine will clean up after itself.  If the
	//  call succeeds, the driver code is left as a memory block in the system
	//  heap, which can be cleaned up by calling TradRemoveDriver.

extern pascal OSErr TradGetDriverInformation(DriverRefNum refNum,
												UnitNumber *thisUnit,
												DriverFlags *flags,
												StringPtr name,
												DRVRHeaderPtr *driverHeader
												);
	// This routine is like GetDriverInformation except that it only
	//  returns information that's pertinant to the traditional 'DRVR'
	//  world.  driverHeader comes back as a pointer to the beginning
	//  of the 'DRVR' header.
	// Note that this routine works for both drivers installed by
	//  this library and other drivers, however for drivers not installed
	//  by this library (ie 'RAM'-based drivers), driverHeader may be a 
	//  half dereferenced handle, locked or unlocked.  You have been warned.
	// Also, driverHeader can come back set to nil, if the driver
	//  is installed but its code has been purged, for example a DA.
	//  You must check for this before deferencing it.  If driverHeader
	//  is set to nil, name will be set to the empty string.

extern pascal OSErr TradOpenInstalledDriver(DriverRefNum refNum, SInt8 ioPermission);
	// This routine has the same semantics as OpenInstalledDriver
	//  except that the ioPermission parameter must be fsRdWrPerm.  This is
	//  because we call through to the Device Manager's OpenDriver routine,
	//  and that doesn't support passing in permissions.  I could switch the
	//  implementation to use PBOpen, but PBOpen is a trap fraught with much
	//  danger, so I'm avoiding it at the moment.
	// The danger associated with PBOpen is that it's highly overloaded,
	//  being used for FSOpen, PBOpen, PBHOpen, OpenSlot, OpenDriver,
	//  OpenDeskAcc, and so on.  If you get the glue wrong, you die in
	//  strange and evil ways.  So I'm bypassing the entire problem by
	//  ignoring ioPermission.  I may revisit this decision, but not soon.

extern pascal OSErr TradRemoveDriver(DriverRefNum refNum, Boolean immediate);
	// This routine implements similar semantics to RemoveDriver, except
	//  that the Immediate parameter must be false.  This is because
	//  we close the driver using PBCloseSync, which is a queued
	//  command, just like all the others.  We have no way to bypass
	//  this.
	// An important thing to note is that you should only call this on drivers
	//  you installed using this library's TradInstallDriverFromHandle
	//  and TradInstallDriverFromResource routine.  Don't call it on
	//  drivers installed by other people and be careful when calling it on
	//  drivers installed using TradInstallDriverFromPtr because you might
	//  be disposing the driver code even though a) it might not actually be a
	//  Memory Manager pointer block, or b) it might be still in use
	//  by another driver.

extern pascal OSErr TradRenameDriver(DriverRefNum refNum, ConstStr255Param newDriverName);
	// This routine is implemented with the caveat that you can't
	//  make the driver name longer.  This is because the 'DRVR'
	//  name is actually stored in the code resource which implements
	//  the driver, and making it longer would cause it to run into
	//  the code that immediately follows the name.
	// The reason why I implemented this routine at all is because
	//  it's useful for installing multiple copies of the same driver.
	//  For example, you can install ".Q_Out", then rename it to
	//  ".QAOut", and then install ".Q_Out" again, and rename that to
	//  ".QBOut".  This can be very useful when testing and debugging
	//  your driver (or TradDriverLoaderLib for that matter :).
	// You should take extreme care when calling this routine on drivers that
	//  weren't installed with this library.  Some of these drivers might
	//  not like being renamed in this way.

///////////////////////////////////////////////////////////////////////////

// The following routines from DriverLoaderLib were not implemented because
//  they make no sense at all in the world of 'DRVR's.

// VerifyFragmentAsDriver
// GetDriverMemoryFragment
// GetDriverDiskFragment
// InstallDriverFromFragment
// SetDriverClosureMemory
// -- If they've got fragment in the name, it's hard to map them into the
// 'DRVR' world.  Traditional 'DRVR's just aren't code fragments!

// InstallDriverFromFile -- This routine assumes that there's only
//	one driver in a file, which is not the case for traditional 'DRVR's
//  which are normally stored as resources.  The basic functionality has
//  been subsumed by TradInstallDriverFromResource.

// InstallDriverFromDisk
// FindDriversForDevice
// FindDriverCandidates
// ScanDriverCandidates
// GetDriverForDevice
// InstallDriverForDevice
// -- These routines all assume that there's some magic way of matching
//  drivers to their name register nodes.  In the traditional world, there
//  is no name registry and, even if there was, there's no way to match
//  devices against hardware.  So these routines are not sensible in the
//  traditional world. 

// ReplaceDriverWithFragment -- There's no good way to replace a traditional
//  device driver; the infrastructure just isn't there.

#ifdef __cplusplus
}
#endif
