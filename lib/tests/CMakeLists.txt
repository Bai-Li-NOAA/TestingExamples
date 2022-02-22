# Third level CMakeLists.txt: register individual tests

include(GoogleTest)

# Simple examples: specify add_executable and target_link_libraries 
add_executable(test_dlognorm
  test_dlognorm.cpp
)

target_link_libraries(test_dlognorm
  gtest_main
  simple_examples
)

add_executable(test_absum
  test_absum.cpp
)

target_link_libraries(test_absum
  gtest_main
  simple_examples
)

# Advanced examples: specify add_executable and target_link_libraries 
add_executable(test_recruitment
  test_recruitment.cpp
)

target_link_libraries(test_recruitment
  gtest_main
  GTest::gmock
  advanced_examples
)

gtest_discover_tests(test_dlognorm)
gtest_discover_tests(test_absum)
gtest_discover_tests(test_recruitment)

# Benchmarking examples
add_executable(benchmark_dlognorm
  benchmark_dlognorm.cpp
)

target_link_libraries(benchmark_dlognorm
  simple_examples
  benchmark_main
)