cmake_minimum_required(VERSION 3.6)
project(gengine)

set(CMAKE_CSS_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${SOURCE_DIR}/classes/*.cpp"
    "${SOURCE_DIR}/classes/math/*.cpp"
    "${SOURCE_DIR}/classes/math/vector/*.cpp"
)

add_executable(gengine ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)
