# Second level CMakeLists.txt: specify individual files and folders to be included

# Simple examples
# The examples demonstrate how to test TMB functions, but they are not necessarily the best practice. Please see advanced examples for C++ testing examples
add_library(simple_examples
  src/absum.hpp
  src/dlognorm.hpp
)

# When use .hpp as file extension, CMake could not tell what it is and set_target_properties is needed
set_target_properties(simple_examples
  PROPERTIES 
    LINKER_LANGUAGE CXX
)
# This code sections will check in all the code from src folder and make the include sections in the .hpp files clean
target_include_directories(simple_examples
  PUBLIC
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