#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace DriveSizeApi {

	/// <summary>
	/// Summary for DiskDrive
	/// </summary>
	public ref class DiskDrive
	{
	public:
		property String ^ DriveLetter;
		property Int64 Size;
		property Int64 FreeSize;

		DiskDrive(void)
		{
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DiskDrive()
		{
		}
	};
}
