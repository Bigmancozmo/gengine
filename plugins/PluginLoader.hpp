#ifndef PLUGIN_LOADER_HPP
#define PLUGIN_LOADER_HPP

#include "Plugin.h"
#include <windows.h>
#include <iostream>

struct PluginHandle {
    HMODULE lib;
    IPlugin* plugin;
    void (*destroy)(IPlugin*);
};

class PluginLoader {
public:
	static PluginHandle loadPlugin(const char* path);
    static void unloadPlugin(PluginHandle& handle);
};

#endif PLUGIN_LOADER_HPP