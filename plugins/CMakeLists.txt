add_library(MyPlugin SHARED "MyPlugin/plugin.cpp" "plugin_interface.h" "PluginLoader.cpp" "../src/classes/Logger.cpp")
target_include_directories(MyPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glad/include)
