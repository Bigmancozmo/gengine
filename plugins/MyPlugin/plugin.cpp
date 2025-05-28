#include "../plugin_interface.h"
#include <iostream>

class MyPlugin : public IPlugin {
public:
    void run() override {
        logger->log(SUCCESS, "Plugin loaded successfully");
    }

    void update() override {
        
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
