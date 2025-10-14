ADD_EXECUTABLE(Tests
  stress_tests.cc
  unit_tests.cc)

TARGET_LINK_LIBRARIES(Tests Private Renn gtest_main)
INCLUDE(CTest)

ADD_TEST(
  NAME tests
  COMMAND Tests
)
