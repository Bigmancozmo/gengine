cmake_minimum_required(VERSION 3.6)
project(gengine)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCES
    "${SOURCE_DIR}/classes/math/*.cpp"
    "${SOURCE_DIR}/classes/math/vector/*.cpp"
    "${SOURCE_DIR}/classes/data/*.cpp"
)

file(GLOB TESTS
    "*.cc"
    "math/*.cc"
    "data/*.cc"
)

add_executable(
  gengine_tests
  ${TESTS}
  ${SOURCES}
)
target_link_libraries(
  gengine_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gengine_tests)