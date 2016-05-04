#pragma once

#include <Windows.h>
#include "DiskDrive.h"
#include <msclr\marshal.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
using namespace msclr::interop;

namespace DriveSizeApi {

	/// <summary>
	/// Summary for DiskDriveEnumerator
	/// </summary>
	public ref class DiskDriveEnumerator
	{
	public:
		DiskDriveEnumerator(void)
		{
		}

		System::Collections::Generic::IEnumerable<DiskDrive^> ^ GetDrives();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DiskDriveEnumerator()
		{

		}

	private:
		static Dictionary<long, String^> ^ _driveLetters = _driveLetterInitializer();
		static Dictionary<long, String^> ^ _driveLetterInitializer();
	};
}
