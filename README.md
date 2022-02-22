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