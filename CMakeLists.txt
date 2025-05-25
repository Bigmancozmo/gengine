cmake_minimum_required(VERSION 3.8)
project(gengine)

set(CMAKE_CSS_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(RESOURCES_SRC "${CMAKE_SOURCE_DIR}/src/resources")
set(RESOURCES_DST "${CMAKE_BINARY_DIR}/resources/")

IF((CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo") OR (CMAKE_BUILD_TYPE STREQUAL "Release"))
    message("Correct build type found")
ELSE()
    message(FATAL_ERROR "Make sure you're running with your build type set to RelWithDebInfo or Release!\n(CMAKE_BUILD_TYPE was ${CMAKE_BUILD_TYPE})")
ENDIF()

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

file(GLOB LIB_SOURCES
    "${LIB_DIR}/glad/src/glad.c"
)

add_executable(gengine ${SOURCES} ${LIB_SOURCES})

target_include_directories(gengine PRIVATE "${LIB_DIR}/glad/include" "${LIB_DIR}/glm")

find_package(OpenGL REQUIRED)

target_link_libraries(gengine PRIVATE glfw OpenGL::GL)

add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${RESOURCES_DST} # Delete the existing resources directory
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_SRC} ${RESOURCES_DST} # Copy updated resources
    COMMENT "Copying resources to build directory"
)

add_dependencies(gengine copy_resources)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)