project(gengine)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCES
    "${SOURCE_DIR}/classes/math/*.cpp"
    "${SOURCE_DIR}/classes/math/vector/*.cpp"
)

add_executable(
  gengine_tests
  vector_test.cc
  ${SOURCES}
)
target_link_libraries(
  gengine_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gengine_tests)