#include "stdafx.h"
#include "DiskDriveEnumerator.h"

namespace DriveSizeApi {
	System::Collections::Generic::IEnumerable<DiskDrive^> ^ DiskDriveEnumerator::GetDrives() {
		DWORD driveListBitfield = GetLogicalDrives();
		List<DiskDrive^> ^ driveList = gcnew List<DiskDrive^>();
		for each (KeyValuePair<long, String^> kvp in _driveLetters)
		{
			if ((driveListBitfield & kvp.Key) == kvp.Key) {
				DiskDrive ^ drive = gcnew DiskDrive();
				drive->DriveLetter = kvp.Value;

				ULARGE_INTEGER freeSpace;
				ULARGE_INTEGER totalSpace;
				ULARGE_INTEGER availableSpace;

				marshal_context context;

				LPCWSTR driveLetter = context.marshal_as<LPCWSTR>(kvp.Value);
				GetDiskFreeSpaceEx(driveLetter, &freeSpace, &totalSpace, &availableSpace);

				drive->FreeSize = freeSpace.QuadPart;
				drive->Size = totalSpace.QuadPart;

				driveList->Add(drive);
			}
		}

		return driveList;
	}

	Dictionary<long, String^> ^ DiskDriveEnumerator::_driveLetterInitializer() {
		Dictionary<long, String^> ^ retVal = gcnew Dictionary<long, String^>();
		retVal->Add(0x00000001, "A:\\");
		retVal->Add( 0x00000002, "B:\\" );
		retVal->Add( 0x00000004, "C:\\" );
		retVal->Add( 0x00000008, "D:\\" );
		retVal->Add( 0x00000010, "E:\\" );
		retVal->Add( 0x00000020, "F:\\" );
		retVal->Add( 0x00000040, "G:\\" );
		retVal->Add( 0x00000080, "H:\\" );
		retVal->Add( 0x00000100, "I:\\" );
		retVal->Add( 0x00000200, "J:\\" );
		retVal->Add( 0x00000400, "K:\\" );
		retVal->Add( 0x00000800, "L:\\" );
		retVal->Add( 0x00001000, "M:\\" );
		retVal->Add( 0x00002000, "N:\\" );
		retVal->Add( 0x00004000, "O:\\" );
		retVal->Add( 0x00008000, "P:\\" );
		retVal->Add( 0x00010000, "Q:\\" );
		retVal->Add( 0x00020000, "R:\\" );
		retVal->Add( 0x00040000, "S:\\" );
		retVal->Add( 0x00080000, "T:\\" );
		retVal->Add( 0x00100000, "U:\\" );
		retVal->Add( 0x00200000, "V:\\" );
		retVal->Add( 0x00400000, "W:\\" );
		retVal->Add( 0x00800000, "X:\\" );
		retVal->Add( 0x01000000, "Y:\\" );
		retVal->Add(0x02000000, "Z:\\");
		return retVal;
	}
}