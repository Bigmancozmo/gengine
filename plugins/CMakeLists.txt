message(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB PLUGIN_FOLDERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/plugins
	${CMAKE_CURRENT_SOURCE_DIR}/plugins/*
)

set(PLUGIN_INCLUDE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
    "${CMAKE_CURRENT_SOURCE_DIR}/../lib/glad/include"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

set(GENERIC_PLUGIN_SOURCES # all plugins will compile with these sources
    "PluginLoader.cpp"
    "../src/classes/Logger.cpp"
)

foreach(FOLDER ${PLUGIN_FOLDERS})
    message("yes yes yes i see ${FOLDER}")
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/plugins/${FOLDER}")
        add_library(${FOLDER} SHARED "${CMAKE_CURRENT_SOURCE_DIR}/plugins/${FOLDER}/plugin.cpp" ${GENERIC_PLUGIN_SOURCES})
        target_include_directories(${FOLDER} PUBLIC ${PLUGIN_INCLUDE_DIRS})
    endif()
endforeach()
