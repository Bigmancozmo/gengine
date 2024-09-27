cmake_minimum_required(VERSION 3.2)
project(gengine)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${SOURCE_DIR}/classes/*.cpp"
    "${SOURCE_DIR}/classes/math/*.cpp"
    "${SOURCE_DIR}/classes/math/vector/*.cpp"
)

set(CMAKE_CXX_STANDARD 11)

add_executable(gengine ${SOURCES})