# Additional C++ Exercises!
This repository contains a collection of exercises for C++, designed for Prof. Azhar's CSC211H course at BMCC.

## Repository Structure
```text
You are Here!
│
│
├── README.md
├── exercises
│   ├── PathFinding
│   │   ├── measuring-distances-I
│   │   ├── measuring-distances-II
│   │   └── permutations
│   └── templates
├── tests
└── tutorial
    └── sqlite
```
    
## How to use Exercises
1. Fork this repository to your own GitHub account.
2. Clone your forked repository to your local machine.
3. Enter any of the exercise directories and follow the instructions in each file.
   1. You will usually define functions in a separate file, but can test them yourself in the main function or use the
   provided test executable.
   
## Build
This repository relies on CMake to build the code. You can install CMake from [here](https://cmake.org/download/) if
you are running this on your own computer and do not already have CMake installed. If you are using Repl.it, read the
instructions following.

1. Create a build directory in the root of the repository.
2. Run `cmake ..` in the build directory.
3. Run `make` in the build directory. (Every time you want to recompile)
4. Run the appropriate executable in the build directory.
    1. Each exercise produces two executables: one with your own main function and one for testing purposes.
   2. The testing executable will be called `<exercise_name>_test`, and main will be called `<exercise_name>`.

For simplicity:
```bash
mkdir build
cd build
cmake ..
make
```


### Repl.it Instructions
If you are using Repl.it, you may get a warning that CMake is not installed. You can ignore this warning, as CMake is
installed on the Repl.it servers. When you run `cmake ..`, just press enter to accept the default CMake option, and
then press enter again to accept the default build type if prompted.

## Running Tests
There are a number of test targets generated, mostly with obvious names like `exercise_1_test`. Run these as any 
executable in the build directory.

### Newer Tests
Some of the later tests are written to support the use of tags to run more specific test cases.
To run a specific test, run `<test-name> "[<tag1>][<tag2>]..."`.
For example, to run the easy tests in templates, run `templates "[easy]"`.
To run a specific NAMED test (not by tag), run `<test-name> "<test-name>"`.

Tests with these capabilities will have the tags listed clearly in the exercise.
