#include "Plugin.h"

class MyPlugin : PLUGIN {
public:
    void run() override {
        logger->log(SUCCESS, "MyPlugin custom start message");
    }
};

DEFINE_PLUGIN(MyPlugin);