#ifndef INTERNET_FILES_H
#define INTERNET_FILES_H

#include <iostream>
#include <Windows.h>
#include <string>
#pragma comment(lib, "urlmon.lib")

namespace gengine {
	class Internet {
		public:
			static HRESULT Download(std::string url, std::string target);
		};
}

#endif // INTERNET_FILE_H
