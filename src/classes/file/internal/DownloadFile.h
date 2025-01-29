#ifndef DOWNLOAD_FILE_H
#define DOWNLOAD_FILE_H

#include <iostream>
#include <Windows.h>
#include <string>
#pragma comment(lib, "urlmon.lib")

namespace gengine {
	class DownloadFile {
	public:
		void Download();
	};
}

#endif // DOWNLOAD_FILE_H