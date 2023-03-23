cmake_minimum_required(VERSION 3.24)
project(azhar_path)

set(CMAKE_CXX_STANDARD 17)

include_directories(exercises)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Standard Targets
add_executable(main main.cpp)
add_executable(measuringDistances exercises/measuring-distances-I/measuringDistances.cpp)
add_executable(measuringDistances2 exercises/measuring-distances-II/measuringDistances2.cpp)
add_executable(permutations exercises/permutations/permutations.cpp)


# Testing Targets
add_executable(permutation_test tests/permutations_test.cpp)
add_executable(measuringDistances_test tests/measuringDistances_test.cpp)
add_executable(measuringDistances2_test tests/measuringDistances2_test.cpp)
add_executable(main_test tests/main_tests.cpp)
add_executable(solution tests/solution.cpp)

Include(FetchContent)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

target_link_libraries(permutation_test PRIVATE Catch2::Catch2WithMain)
#catch_discover_tests(permutation_test)

target_link_libraries(measuringDistances_test PRIVATE Catch2::Catch2WithMain)
#catch_discover_tests(measuringDistances_test)

target_link_libraries(measuringDistances2_test PRIVATE Catch2::Catch2WithMain)
#catch_discover_tests(measuringDistances2_test)

target_link_libraries(main_test PRIVATE Catch2::Catch2WithMain)
#catch_discover_tests(main_test)

