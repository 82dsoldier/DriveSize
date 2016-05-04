#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

namespace DriveSizeApi {

	/// <summary>
	/// Summary for DriveFolder
	/// </summary>
	generic <class T>
	public ref class DriveFolder : public System::Collections::Generic::IEnumerable<T>
	{
	public:
		property String ^ Name;
		property Int64 UsedSpace;
		property List<DriveFolder^> ^ Folders;
		DriveFolder(void)
		{
		}

		ref struct enumerator : IEnumerator<T> {
			DriveFolder ^ colInst;
			int currentIndex;

			enumerator(DriveFolder ^ folder) {
				colInst = folder;
				currentIndex = -1;
			}

			virtual bool MoveNext() = IEnumerator<T>::MoveNext{
				if (currentIndex < colInst->Folders->Length) {
					currentIndex++;
					return true;
				}

				return false;
			}

			property T Current {
				virtual T get() = IEnumeratlr<T>::Current::get{
					return colInst->data[currentIndex];
				}
			};

			property Object ^ Current2 {
				virtual Object ^ get() = System::Collections::IEnumerator::Current::get{
					return colInst->data[currentIndex];
				}
			};

			virtual void Reset() = IEnumerator<T>::Reset{}
			~enumerator(){}
		};

		virtual IEnumerator<T> ^ GetEnumerator() {
			return gcnew enumerator(this);
		}

		virtual System::Collections::IEnumerator ^ GetEnumerator2() = System::Collections::IEnumerable::GetEnumerator{
			return gcnew enumerator(this);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DriveFolder()
		{
		}
	};
}
