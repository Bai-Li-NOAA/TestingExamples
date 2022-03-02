# TestingExamples
This repository includes a few C++ testing examples using [GoogleTest](https://github.com/google/googletest). 

A top-level directory layout:

```
.
├── .github
│   └──workflows          
│      └── googletest.yml      # GitHub Actions yml workflow
├── lib                    
│   ├── include                # Headers files
│   ├── src                    # Source files
│   ├── tests                  # Unite tests and benchmark code
│   └── CMakeLists.txt         # Specify individual files and folders to be included
└── CMakeLists.txt             # Set up top-level project dependencies and options
```

Automated tests are placed inside of the `tests` folder. 

- Simple tests

    - `test_dlognorm.cpp` tests the dlognorm function and `benchmark_dlognorm.cpp` benchmarks the code.

    - `test_absum.cpp` tests a typical TMB function that depends on other functions.

- Advanced tests
    - `test_recruitment.cpp` demonstrates how to set up test fixture class when multiple tests in a test suite need to share common objects and subroutines. It also shows how to set up a mock object that implements the same interface as a real object. You can specify how it will be used and how many times it will be used in a test.

To run the tests, you can use the commands below:
```bash
cmake -S . -B build -G Ninja
cd build 
cmake --build . --parallel 16
ctest
```
Here `--parallel 16` means that the maximum number of concurrent processes to use when building is 16. 

To build and run tests without navigating to the `build` folder, you can use the commands below:
```bash
cmake -S . -B build -G Ninja 
cmake --build build --parallel 16
ctest --test-dir build
```
