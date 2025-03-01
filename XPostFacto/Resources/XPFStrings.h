/*

Copyright (c) 2001 - 2003
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

#ifndef __XPFSTRINGS_H__

#define kXPFStringsResource 2000

#define kStatusOK	0

enum {
	kNotBootable = 1,
	kNotHFSPlus,
	kNoMachKernel,
	kNoOFName,
	kNoOldWorldSupport,			// 5
	kNoBootX,
	kPast8GB,
	kNotWriteable,
	kNotInstaller,
	kRequiresOS9,				// 10
	kNoNVRAMPatches,
	kNoMacOSXYet,
	kXPostFactoHelpMenu,
	kXPostFactoOnlineHelpMenu,
	kXPostFactoSourceCodeMenu,	// 15
	kInstallOnly,
	kNeedsHelper,
	kShowLogWindowMenu,
	kTheWordCopy,
	kRestarting,				// 20
	kInstalling,
	kInstallingBootX,
	kInstallingExtensions,
	kInstallingStartupItem,
	kUpdatingExtensionsCache,	// 25
	kShowDebugOptions,
	kHideDebugOptions,
	kMenuDisableRestart,
	kMenuDisableNVRAM,
	kMenuDisableBootX,			// 30
	kMenuDisableStartupItem,
	kMenuDisableExtensions,
	kMenuDisableExtensionsCache,
	kMenuDisableCoreServices,
	kMenuDisableHelperCopy,		// 35
	kMenuVisibleHelper,
	kRecopyingHelperFiles,
	kUpdating,
	kTooBigForNVRAM,
	kTooBigForNVRAMForInstall,	// 40
	kInstallWord,
	kDeleteWord,
	kSynchronizing,
	kUninstalling,
	kBlessingSystemFolder,		// 45
	kDeletingXPFCache,
	kCheckingPermissions,
	kXPostFactoRegisterMenu,
	kCPUG3Required,
	kNotInstalled,				// 50
	kFewerPartitionsThanExpected,
	kInvalidSymlinks,
	kInvalidSymlinksCannotFix,
	kFixingSymbolicLinks,
	kNoHFSWrapper,				// 55
	kBogus8GBWarning,
	k8GBWarning,
	kRequiresInstallation,
	kNoPartitionNumber,
	kUsingNonDefaultBus,		// 60
	kXPostFactoName,
	kSaveCurrentLog,
	kXPostFactoLog,
	kNotInitialized,
	kExtensionsCacheInvalid,	// 65
	kNotSufficientRAM,
	kNoMacOS9SystemFolder,
	kRequiresTenPointTwo,
	kCPUPPC603Required,
	kCPUG4Required,				// 70
	kCPUIntelRequired,
	kNoHFSWrapperNote,
};


#endif