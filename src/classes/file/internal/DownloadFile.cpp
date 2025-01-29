#include "DownloadFile.h"

using namespace gengine
int Download()
{
    string dwnld_URL = "https://github.com/Bigmancozmo/gengine/archive/refs/heads/resources.zip";
    string savepath = "C:/Users/h/Downloads/resources.zip";
    URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);

    return 0;
}

/// TODO implement this properly