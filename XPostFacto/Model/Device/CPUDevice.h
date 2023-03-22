/*

CPUDevice
=========

The function of this class is to maintain a list of all the name registry
entries that are CPUs.

*/

#ifndef __CPUDEVICE_H__
#define __CPUDEVICE_H__

#include "OFAliases.h"

class CPUDevice;

typedef TemplateAutoList_AC <CPUDevice> CPUDeviceList;
typedef TemplateAutoList_AC <CPUDevice>::Iterator CPUDeviceIterator;

class CPUDevice {

	public:

		static void Initialize ();

		static CPUDevice* CPUWithNumber (int number);
		static CPUDevice* CPUWithRegEntryID (REG_ENTRY_TYPE regEntry);
		static CPUDevice* CPUWithOpenFirmwareName (char *ofName);

		static int getCPUCount () {return gCPUCount;}
		static CVoidList_AC* GetCPUList () {return &gCPUDeviceList;}

		~CPUDevice ();

		RegEntryID fRegEntryIDStorage;
		REG_ENTRY_TYPE fRegEntryID;
		char fOpenFirmwareName[256];
		char fShortOpenFirmwareName[256];
		UInt32 fCPUNumber;
		UInt32 fCPUVersion;

	private:

		CPUDevice (REG_ENTRY_TYPE regEntry);

		static CPUDeviceList gCPUDeviceList;
		static int gCPUCount;
		static bool gHasBeenInitialized;

};

#endif
