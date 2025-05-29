#ifndef PLUGIN_IMGUI_HPP
#define PLUGIN_IMGUI_HPP

#include <imgui.h>

class PluginImGui {
public:
    void Begin(const char* name);
    void Text(const char* fmt, ...);
    void End();
};

#endif // PLUGIN_IMGUI_HPP