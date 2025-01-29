#include "InternetFiles.h"

using namespace gengine
static void Download(std::string url, std::string target)
{
    HRESULT result = URLDownloadToFile(NULL, url.c_str(), target.c_str(), 0, NULL);
}
