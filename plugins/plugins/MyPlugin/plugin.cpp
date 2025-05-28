#include "Plugin.h"
#include <iostream>

class MyPlugin : public IPlugin {
public:
    void run() override {
        logger->log(SUCCESS, "the plugin haseth loaded successfully");
    }
};

extern "C" {
    IPlugin* create_plugin() {
        return new MyPlugin();
    }

    void destroy_plugin(IPlugin* p) {
        delete p;
    }
}
