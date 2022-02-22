# Second level CMakeLists.txt: specify individual files and folders to be included

# Simple examples
# The examples demonstrate how to test TMB functions, but they are not necessarily the best practice. Please see advanced examples for C++ testing examples
# Because we do not have any .cpp code, only template headers (e.g., src/absum.hpp and src/dlognorm.hpp), so we do not include individule template .hpp files here but use INTERFACE
add_library(simple_examples INTERFACE)

# CMake target: 
# Public (I need the includes and dependents need the includes)
# Private (Only I need the includes)
# Interface (Only dependents need the includes)
target_include_directories(simple_examples
  INTERFACE
    src
)

# Advanced examples
# Test fixture class: use test fixture class when multiple tests in a test suite use shared common objects and subroutines (e.g., see SumToZeroTest in the test_sum_to_zero.cpp)
# gMock: use mock object to implement the same interface as a real object and then specify which method will be called how manys times (e.g. see PredictedRecruitment in the test_sum_to_zero.cpp)

add_library(advanced_examples
  src/deviations.cpp
  src/recruitment.cpp
)

# This code sections will check in all the code from include folder and make the include sections in the .hpp files clean
target_include_directories(advanced_examples
  PUBLIC
    include
)

add_subdirectory(tests)