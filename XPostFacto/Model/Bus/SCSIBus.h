/*

Copyright (c) 2001 - 2004
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

/*

SCSIBus
=======

The function of this class is to maintain a list of all the name registry
entries that might be SCSI buses. Matching a SCSI device to a name registry entry
turns out to be a lot harder than you might think.

*/

#ifndef __SCSIBUS_H__
#define __SCSIBUS_H__

#include "XPFBus.h"

class SCSIBus;

typedef TemplateAutoList_AC <SCSIBus> SCSIBusList;
typedef TemplateAutoList_AC <SCSIBus>::Iterator SCSIBusIterator;

class SCSIBus : public XPFBus {

	public:
				
		static SCSIBus* BusWithNumber (int number);
		static SCSIBus* BusWithRegEntryID (RegEntryID *regEntry);
		static SCSIBus* BusWithOpenFirmwareName (char *ofName);
		static SCSIBus* GetDefaultBus () {return gSCSIBusList.Last ();}

		static void Initialize ();
		static int getBusCount () {return gBusCount;}
		static CVoidList_AC* GetBusList () {return &gSCSIBusList;}
		
		const char* getATAOpenFirmwareName (int channel, bool useShortName);
		
		virtual bool getIsActuallyATABus () {return fIsActuallyATABus;}
		
		~SCSIBus ();

	private:
	
		SCSIBus (RegEntryID *scsiEntry);
					
		bool fIsActuallyATABus;
		char fATAOpenFirmwareName0[256];
		char fATAShortOpenFirmwareName0[256];
		char fATAOpenFirmwareName1[256];
		char fATAShortOpenFirmwareName1[256];
		
		static int gBusCount;
		static SCSIBusList gSCSIBusList;
		static bool gHasBeenInitialized;
		
};

#endif