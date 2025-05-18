#include "InternetFiles.h"

HRESULT gengine::Internet::Download(std::string url, std::string target)
{
	HRESULT result = URLDownloadToFile(NULL, url.c_str(), target.c_str(), 0, NULL);
	return result;
}
