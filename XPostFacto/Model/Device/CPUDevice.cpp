#include "CPUDevice.h"

#include "XPFLog.h"
#include "OFAliases.h"

#include <NameRegistry.h>

CPUDeviceList CPUDevice::gCPUDeviceList;
bool CPUDevice::gHasBeenInitialized = false;
int CPUDevice::gCPUCount = 0;

#define kDeviceTypeProperty "device_type"

void
CPUDevice::Initialize ()
{
	if (gHasBeenInitialized) return;

	gHasBeenInitialized = true;

	// We iterate through, and collected all entries with a device type "cpu"

#ifdef __MACH__

	io_object_t rootEntry = IORegistryGetRootEntry(kIOMasterPortDefault);
	if (rootEntry) {
		io_iterator_t iter = NULL;
		IORegistryEntryCreateIterator (rootEntry, kIODeviceTreePlane, kIORegistryIterateRecursively, &iter);
		if (iter) {
			io_object_t entry;
			while ((entry = IOIteratorNext (iter)) != NULL) {
				bool doRelease = true;
				CFTypeRef cfValue = IORegistryEntryCreateCFProperty (entry, CFSTR("device_type"), NULL, NULL);
				if (cfValue) {
					if (CFGetTypeID (cfValue) == CFDataGetTypeID ()) {
						UInt32 propSize = CFDataGetLength ((CFDataRef) cfValue);
						char *deviceType = NewPtr (propSize + 1);
						ThrowIfNULL_AC (deviceType);
						CFDataGetBytes ((CFDataRef) cfValue, CFRangeMake (0, propSize), (UInt8*) deviceType);
						deviceType[propSize] = '\0';
						if (!strcmp (deviceType, "cpu")) {
							CPUDevice *newCPU = new CPUDevice (entry);
							gCPUDeviceList.InsertLast (newCPU);
							gCPUCount++;
							doRelease = false;
						}
						DisposePtr (deviceType);
					}
					CFRelease (cfValue);
				}
				if (doRelease) IOObjectRelease (entry);
			}
			IOObjectRelease (iter);
		}
		IOObjectRelease (rootEntry);
	}

#else

	RegEntryIter cookie;
    RegEntryID entry;
    Boolean done = false;
    RegEntryIterationOp iterOp = kRegIterDescendants;
    OSStatus err = RegistryEntryIterateCreate (&cookie);

    while (true) {
        err = RegistryEntryIterate (&cookie, iterOp, &entry, &done);
        if (!done && (err == noErr)) {
  			RegPropertyValueSize propSize;
  			err = RegistryPropertyGetSize (&entry, kDeviceTypeProperty, &propSize);
  			if (err == noErr) {
				char *deviceType = NewPtr (propSize + 1);
				ThrowIfNULL_AC (deviceType);
				ThrowIfOSErr_AC (RegistryPropertyGet (&entry, kDeviceTypeProperty, deviceType, &propSize));
				deviceType[propSize] = '\0';
				if (!strcmp (deviceType, "cpu")) {
					CPUDevice *newCPU = new CPUDevice (&entry);
					gCPUDeviceList.InsertLast (newCPU);
					gCPUCount++;
				}
				DisposePtr (deviceType);
			}
	        RegistryEntryIDDispose (&entry);
        } else {
        	break;
        }
        iterOp = kRegIterContinue;
    }
    RegistryEntryIterateDispose (&cookie);

#endif
}


CPUDevice::~CPUDevice ()
{
#ifdef __MACH__
#else
	RegistryEntryIDDispose (fRegEntryID);
#endif
}

#define kCPUIDPropName "cpu#"
#define kCPUVersionPropName "cpu-version"

CPUDevice::CPUDevice (REG_ENTRY_TYPE regEntry)
{
#ifdef __MACH__
	fRegEntryID = regEntry;

	OFAliases::AliasFor (fRegEntryID, fOpenFirmwareName, fShortOpenFirmwareName);

	UInt32 propSize;

	CFTypeRef cfValue;

	fCPUNumber = 0;
	cfValue = IORegistryEntryCreateCFProperty (regEntry, CFSTR(kCPUIDPropName), NULL, NULL);
	if (cfValue) {
		if (CFGetTypeID (cfValue) == CFDataGetTypeID ()) {
			propSize = CFDataGetLength ((CFDataRef) cfValue);
			if (propSize == sizeof (fCPUNumber)) {
				CFDataGetBytes ((CFDataRef) cfValue, CFRangeMake (0, propSize), (UInt8*) &fCPUNumber);
			}
		}
		CFRelease (cfValue);
	}

	fCPUVersion = 0;
	cfValue = IORegistryEntryCreateCFProperty (regEntry, CFSTR(kCPUVersionPropName), NULL, NULL);
	if (cfValue) {
		if (CFGetTypeID (cfValue) == CFDataGetTypeID ()) {
			propSize = CFDataGetLength ((CFDataRef) cfValue);
			if (propSize == sizeof (fCPUVersion)) {
				CFDataGetBytes ((CFDataRef) cfValue, CFRangeMake (0, propSize), (UInt8*) &fCPUVersion);
			}
		}
		CFRelease (cfValue);
	}

#else
	ThrowIfNULL_AC (regEntry);
	RegistryEntryIDCopy (regEntry, &fRegEntryIDStorage);
	fRegEntryID = &fRegEntryIDStorage;

	OFAliases::AliasFor (fRegEntryID, fOpenFirmwareName, fShortOpenFirmwareName);

	RegPropertyValueSize propSize;

	OSErr err;

	fCPUNumber = 0;
	err = RegistryPropertyGetSize (fRegEntryID, kCPUIDPropName, &propSize);
  	if ((err == noErr) && (propSize == sizeof (fCPUNumber))) {
		ThrowIfOSErr_AC (RegistryPropertyGet (regEntry, kCPUIDPropName, &fCPUNumber, &propSize));
	}

	fCPUVersion = 0;
	err = RegistryPropertyGetSize (fRegEntryID, kCPUVersionPropName, &propSize);
  	if ((err == noErr) && (propSize == sizeof (fCPUVersion))) {
		ThrowIfOSErr_AC (RegistryPropertyGet (fRegEntryID, kCPUVersionPropName, &fCPUVersion, &propSize));
	}
#endif

	#if qLogging
		gLogFile << "CPU#: " << fCPUNumber << endl_AC;
		gLogFile << "OpenFirmwareName: " << fOpenFirmwareName << endl_AC;
		gLogFile << "ShortOpenFirmwareName: " << fShortOpenFirmwareName << endl_AC;
		gLogFile << "CPUVersion: " << fCPUVersion << endl_AC;
	#endif
}

CPUDevice*
CPUDevice::CPUWithNumber (int number)
{
	Initialize ();
	CPUDevice *retVal = NULL;
	for (CPUDeviceIterator iter (&gCPUDeviceList); iter.Current(); iter.Next()) {
		if (iter->fCPUNumber == number) {
			retVal = iter.Current ();
			break;
		}
	}
	return retVal;
}

#ifdef __MACH__

#else
CPUDevice*
CPUDevice::CPUWithRegEntryID (REG_ENTRY_TYPE otherRegEntry)
{
	Initialize ();
	CPUDevice *retVal = NULL;
	for (CPUDeviceIterator iter (&gCPUDeviceList); iter.Current(); iter.Next()) {
		if (RegistryEntryIDCompare (iter->fRegEntryID, otherRegEntry)) {
			retVal = iter.Current ();
			#if qLogging
				gLogFile << "Found CPU WithRegEntryID" << endl_AC;
			#endif
			break;
		}
	}
	if (retVal == NULL) {
		// in theory, this shouldn't happen, because we should have already
		// collected all of the possible registry entries. But if it does, we'll
		// just add this one.
		#if qLogging
			gLogFile << "Creating new CPUDevice with RegEntryID" << endl_AC;
		#endif
		retVal = new CPUDevice (otherRegEntry);
		gCPUDeviceList.InsertLast (retVal);
	}
	return retVal;
}
#endif

CPUDevice*
CPUDevice::CPUWithOpenFirmwareName (char *ofName)
{
	Initialize ();
	CPUDevice *retVal = NULL;
	for (CPUDeviceIterator iter (&gCPUDeviceList); iter.Current(); iter.Next()) {
		if (OFAliases::MatchAliases (iter->fOpenFirmwareName, ofName)) {
			retVal = iter.Current ();
			break;
		}
	}
	return retVal;
}
