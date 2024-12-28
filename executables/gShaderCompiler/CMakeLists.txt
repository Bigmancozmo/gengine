project(gengine)
set(ROOT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(gShaderCompiler src/main.cpp)

file(GLOB SOURCES
    "${ROOT_SOURCE_DIR}/internal/renderer/*.cpp"
)