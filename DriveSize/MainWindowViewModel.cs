using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DriveSize {
	public class MainWindowViewModel {
		public ObservableCollection<DriveInfo> DriveList { get; set; }

		public MainWindowViewModel() {
			DriveList = new ObservableCollection<DriveInfo>(DriveInfo.GetDrives());
		}
	}
}
