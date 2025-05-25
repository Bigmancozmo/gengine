#include "PluginLoader.hpp"

PluginHandle PluginLoader::loadPlugin(const char* path)
{
	HMODULE lib = LoadLibraryA(path);
	if (!lib) {
		std::cerr << "Failed to load DLL\n";
		return {};
	}

	auto create = (IPlugin* (*)())GetProcAddress(lib, "create_plugin");
	auto destroy = (void (*)(IPlugin*))GetProcAddress(lib, "destroy_plugin");

	if (!create || !destroy) {
		std::cerr << "Failed to get functions\n";
		FreeLibrary(lib);
		return {};
	}

	Logger* logger = new Logger(std::string(path));

	IPlugin* plugin = create();
	plugin->set_logger(logger);
	plugin->run();
	return { lib, plugin, destroy };
}

void PluginLoader::unloadPlugin(PluginHandle& handle)
{
	handle.destroy(handle.plugin);
	FreeLibrary(handle.lib);
	handle.plugin = nullptr;
	handle.lib = nullptr;
	handle.destroy = nullptr;
}
