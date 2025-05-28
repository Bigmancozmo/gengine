#ifndef PLUGIN_H
#define PLUGIN_H

#ifdef BUILDING_PLUGIN_DLL
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif

#include "../src/classes/Logger.hpp"

using namespace gengine;

class IPlugin {
protected:
    Logger* logger = nullptr;

public:
    virtual void set_logger(Logger* l) { logger = l; }
    virtual void run() { logger->log(SUCCESS, "Plugin loaded successfully"); };
    virtual void update() {};
    virtual ~IPlugin() {}
};

// Base API
extern "C" {
	PLUGIN_API IPlugin* create_plugin();
	PLUGIN_API void destroy_plugin(IPlugin*);
}

#endif // PLUGIN_H