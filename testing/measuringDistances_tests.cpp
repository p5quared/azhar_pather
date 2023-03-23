//
// Created by Peter Vaiciulis on 3/16/23.
//
#include "measuringDistances.cpp"

#include <vector>
#include <string>
#include <catch2/catch_test_macros.hpp>

int pathDistance_solution(const std::vector<int> path, const Matrix& map);

TEST_CASE("Part1: Distance")
{
    SECTION("Map1"){
        Matrix map1 = {
                {0, 10, 20, 30},
                {10, 0, 40, 50},
                {20, 40, 0, 60},
                {30, 50, 60, 0}
        };
        REQUIRE(distance(0, 1, map1) == 10);
        REQUIRE(distance(0, 2, map1) == 20);
        REQUIRE(distance(0, 3, map1) == 30);
        REQUIRE(distance(1, 2, map1) == 40);
        REQUIRE(distance(1, 3, map1) == 50);
        REQUIRE(distance(2, 3, map1) == 60);
    }
    SECTION("Map2"){
        Matrix map2 = {
                {0, 99, 1234, 83},
                {99, 0, 123, 123},
                {1234, 123, 0, 123},
                {83, 123, 123, 0}
        };
        REQUIRE(distance(0, 1, map2) == 99);
        REQUIRE(distance(0, 2, map2) == 1234);
        REQUIRE(distance(0, 3, map2) == 83);
        REQUIRE(distance(1, 2, map2) == 123);
        REQUIRE(distance(1, 3, map2) == 123);
        REQUIRE(distance(2, 3, map2) == 123);
    }
}

TEST_CASE("Part2: Path Distances"){
SECTION("Map1"){
        Matrix map1 = {
                {0, 10, 20, 30},
                {10, 0, 40, 50},
                {20, 40, 0, 60},
                {30, 50, 60, 0}
        };
        std::vector<int> path1 = {0, 1, 2, 3};
        REQUIRE(pathDistance(path1, map1) == pathDistance_solution(path1, map1));

        std::vector<int> path2 = {0, 2, 1, 3};
        REQUIRE(pathDistance(path2, map1) == pathDistance_solution(path2, map1));

        std::vector<int> path3 = {0, 3, 2, 1};
        REQUIRE(pathDistance(path3, map1) == pathDistance_solution(path3, map1));

    }
    SECTION("Map2"){
        Matrix map2 = {
                {0, 99, 1234, 83},
                {99, 0, 123, 123},
                {1234, 123, 0, 123},
                {83, 123, 123, 0}
        };
        std::vector<int> path1 = {0, 1, 2, 3};
        REQUIRE(pathDistance(path1, map2) == pathDistance_solution(path1, map2));

        std::vector<int> path2 = {0, 2, 1, 3};
        REQUIRE(pathDistance(path2, map2) == pathDistance_solution(path2, map2));

        std::vector<int> path3 = {0, 3, 2, 1};
        REQUIRE(pathDistance(path3, map2) == pathDistance_solution(path3, map2));

        std::vector<int> path4 = {0, 3, 1, 2, 1, 3};
        REQUIRE(pathDistance(path4, map2) == pathDistance_solution(path4, map2));
    }

    SECTION("Additional Maps")
    {
    // make a 2d vector representing a distance matrix
    // and a vector representing a path
    Matrix map3 = {
        {0, 1, 2, 3, 4, 5},
        {1, 0, 1, 2, 3, 4},
        {2, 1, 0, 1, 2, 3},
        {3, 2, 1, 0, 1, 2},
        {4, 3, 2, 1, 0, 1},
        {5, 4, 3, 2, 1, 0}
    };
    std::vector<int> path1 = {0, 1, 2, 3, 4, 5};
    REQUIRE(pathDistance(path1, map3) == pathDistance_solution(path1, map3));


    // Make a distance matrix of integers between 100 and 300
    Matrix map4 = {
        {0, 100, 200, 300},
        {100, 0, 200, 300},
        {200, 200, 0, 300},
        {300, 300, 300, 0}
    };
    std::vector<int> path2 = {0, 1, 2, 3};
    REQUIRE(pathDistance(path2, map4) == pathDistance_solution(path2, map4));

    }

}

int pathDistance_solution(const std::vector<int> path, const Matrix& map) {
    int total_distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        total_distance += distance(path[i], path[i + 1], map);
    }
    return total_distance;
}
