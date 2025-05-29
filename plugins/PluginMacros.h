#ifndef PLUGIN_MACROS_H
#define PLUGIN_MACROS_H

#define DEFINE_PLUGIN(ClassName)                              \
extern "C" {                                                  \
    __declspec(dllexport) IPlugin* create_plugin() {          \
        return new ClassName();                               \
    }                                                         \
    __declspec(dllexport) void destroy_plugin(IPlugin* p) {   \
        delete p;                                             \
    }                                                         \
}

#ifdef BUILDING_PLUGIN_DLL
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif

#define PLUGIN public IPlugin

#endif // PLUGIN_MACROS_H