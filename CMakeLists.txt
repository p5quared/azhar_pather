cmake_minimum_required(VERSION 3.24)
project(azhar_path)

set(CMAKE_CXX_STANDARD 17)

include_directories(exercises)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Standard Targets
add_executable(main main.cpp)
add_executable(measuringDistances exercises/measuringDistances.cpp)
add_executable(measuringDistances2 exercises/measuringDistances2.cpp)
add_executable(permutations exercises/permutations.cpp)


# Testing Targets
add_executable(permutation_tests testing/permutations_tests.cpp)
add_executable(measuringDistances_tests testing/measuringDistances_tests.cpp)
add_executable(measuringDistances2_tests testing/measuringDistances2_tests.cpp)
add_executable(solution testing/solution.cpp)
add_executable(main_test testing/main_tests.cpp)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

target_link_libraries(permutation_tests PRIVATE Catch2::Catch2)
catch_discover_tests(permutation_tests)

target_link_libraries(measuringDistances_tests PRIVATE Catch2::Catch2)
catch_discover_tests(measuringDistances_tests)

target_link_libraries(measuringDistances2_tests PRIVATE Catch2::Catch2)
catch_discover_tests(measuringDistances2_tests)

target_link_libraries(main_test PRIVATE Catch2::Catch2)
catch_discover_tests(main_test)

