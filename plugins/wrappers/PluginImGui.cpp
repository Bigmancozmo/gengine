#include "PluginImGui.hpp"

void PluginImGui::Begin(const char* name)
{
    ImGui::Begin(name);
}

void PluginImGui::Text(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImGui::TextV(fmt, args);
    va_end(args);
}

void PluginImGui::End() {
    ImGui::End();
}