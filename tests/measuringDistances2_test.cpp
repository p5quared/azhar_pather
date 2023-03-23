//
// Created by Peter Vaiciulis on 3/16/23.
//
#include <vector>
#include <string>
#include <catch2/catch_test_macros.hpp>

#include "measuring-distances-II/measuringDistances2_helpers.h"
int distance_sol(const std::string& city1,const std::string& city2, const std::vector<std::string>& cities, const
Matrix&
map);
int getPathDistance_sol(const std::vector<std::string> &path, const std::vector<std::string>& cities, const Matrix&
map);



TEST_CASE("Part1: Distances"){
SECTION("Map1"){
        Matrix map1 = {
                {0, 10, 20, 30},
                {10, 0, 40, 50},
                {20, 40, 0, 60},
                {30, 50, 60, 0}
        };
        std::vector<std::string> Cities = {"A", "B", "C", "D"};

        REQUIRE(distance("A", "B", Cities, map1) == 10);
        REQUIRE(distance("A", "C", Cities, map1) == 20);
        REQUIRE(distance("A", "D", Cities, map1) == 30);
        REQUIRE(distance("B", "C", Cities, map1) == 40);
        REQUIRE(distance("B", "D", Cities, map1) == 50);
        REQUIRE(distance("C", "D", Cities, map1) == 60);
    }

    SECTION("Map2"){
        Matrix map2 = {
                {0, 99, 1234, 83},
                {99, 0, 123, 123},
                {1234, 123, 0, 123},
                {83, 123, 123, 0}
        };
        std::vector<std::string> Cities2 = {"New York", "Chicago", "Los Angeles", "Houston"};

        REQUIRE(distance("New York", "Chicago", Cities2, map2) == 99);
        REQUIRE(distance("New York", "Los Angeles", Cities2, map2) == 1234);
        REQUIRE(distance("New York", "Houston", Cities2, map2) == 83);
        REQUIRE(distance("Chicago", "Los Angeles", Cities2, map2) == 123);
        REQUIRE(distance("Chicago", "Houston", Cities2, map2) == 123);
        REQUIRE(distance("Los Angeles", "Houston", Cities2, map2) == 123);
    }

    SECTION("Additional Maps"){
    Matrix map3 = {
            {0, 10, 20, 30, 40},
            {10, 0, 50, 60, 70},
            {20, 50, 0, 80, 90},
            {30, 60, 80, 0, 100},
            {40, 70, 90, 100, 0}
    };
    std::vector<std::string> Cities3 = {"A", "B", "C", "D", "E"};

    REQUIRE(distance("A", "B", Cities3, map3) == 10);
    REQUIRE(distance("A", "C", Cities3, map3) == 20);
    REQUIRE(distance("A", "D", Cities3, map3) == 30);
    REQUIRE(distance("A", "E", Cities3, map3) == 40);
    REQUIRE(distance("B", "C", Cities3, map3) == 50);
    REQUIRE(distance("B", "D", Cities3, map3) == 60);
    REQUIRE(distance("B", "E", Cities3, map3) == 70);
    REQUIRE(distance("C", "D", Cities3, map3) == 80);
    REQUIRE(distance("C", "E", Cities3, map3) == 90);
    REQUIRE(distance("D", "E", Cities3, map3) == 100);
    }
}

TEST_CASE("Part2: Path Distances"){
    SECTION("Map1"){
        std::vector<std::string> Cities = {"A", "B", "C", "D"};
        Matrix map1 = {
                {0, 10, 20, 30},
                {10, 0, 40, 50},
                {20, 40, 0, 60},
                {30, 50, 60, 0}
        };

        Path path1 = {"A", "B", "C", "D"};
        REQUIRE(getPathDistance(path1, Cities, map1) == getPathDistance_sol(path1, Cities, map1));

        Path path2 = {"A", "C", "B", "D"};
        REQUIRE(getPathDistance(path2, Cities, map1) == getPathDistance_sol(path2, Cities, map1));

        Path path3 = {"A", "D", "C", "B"};
        REQUIRE(getPathDistance(path3, Cities, map1) == getPathDistance_sol(path3, Cities, map1));

        Path path4 = {"A", "B", "D", "C"};
        REQUIRE(getPathDistance(path4, Cities, map1) == getPathDistance_sol(path4, Cities, map1));

        Path path5 = {"A", "C", "D", "B"};
        REQUIRE(getPathDistance(path5, Cities, map1) == getPathDistance_sol(path5, Cities, map1));

        Path path6 = {"A", "B", "C"};
        REQUIRE(getPathDistance(path6, Cities, map1) == getPathDistance_sol(path6, Cities, map1));

        Path path7 = {"A", "C", "B"};
        REQUIRE(getPathDistance(path7, Cities, map1) == getPathDistance_sol(path7, Cities, map1));

        Path path8 = {"A", "D", "C", "B", "A"};
        REQUIRE(getPathDistance(path8, Cities, map1) == getPathDistance_sol(path8, Cities, map1));
    }

    SECTION("Map2"){
        Matrix map2 = {
                {0, 99, 1234, 83},
                {99, 0, 123, 123},
                {1234, 123, 0, 123},
                {83, 123, 123, 0}
        };
        std::vector<std::string> Cities2 = {"New York", "Chicago", "Los Angeles", "Houston"};

        Path path1 = {"New York", "Chicago", "Los Angeles", "Houston"};
        REQUIRE(getPathDistance(path1, Cities2, map2) == getPathDistance_sol(path1, Cities2, map2));

        Path path2 = {"New York", "Los Angeles", "Chicago", "Houston"};
        REQUIRE(getPathDistance(path2, Cities2, map2) == getPathDistance_sol(path2, Cities2, map2));

        Path path3 = {"New York", "Houston", "Chicago", "Los Angeles"};
        REQUIRE(getPathDistance(path3, Cities2, map2) == getPathDistance_sol(path3, Cities2, map2));

        Path path4 = {"New York", "Chicago", "Houston", "Los Angeles"};
        REQUIRE(getPathDistance(path4, Cities2, map2) == getPathDistance_sol(path4, Cities2, map2));

        Path path5 = {"New York", "Los Angeles", "Houston", "Chicago"};
        REQUIRE(getPathDistance(path5, Cities2, map2) == getPathDistance_sol(path5, Cities2, map2));

        Path path6 = {"New York", "Chicago", "Los Angeles"};
        REQUIRE(getPathDistance(path6, Cities2, map2) == getPathDistance_sol(path6, Cities2, map2));

        Path path7 = {"New York", "Los Angeles", "Chicago"};
        REQUIRE(getPathDistance(path7, Cities2, map2) == getPathDistance_sol(path7, Cities2, map2));

        Path path8 = {"New York", "Houston", "Chicago", "Los Angeles", "New York"};
        REQUIRE(getPathDistance(path8, Cities2, map2) == getPathDistance_sol(path8, Cities2, map2));
    }

    SECTION("Additional Map"){
        Matrix map3 = {
                {0, 307, 833, 880, 900, 399, 419, 301, 356},
                {307, 0, 376, 423, 443, 706, 726, 608, 663},
                {833, 376, 0, 47, 67, 1082, 1102, 984, 1039},
                {880, 423, 47, 0, 20, 1129, 1149, 1031, 1086},
                {900, 443, 67, 20, 0, 1149, 1169, 1051, 1106},
                {399, 706, 1082, 1129, 1149, 0, 20, 98, 143},
                {419, 726, 1102, 1149, 1169, 20, 0, 118, 163},
                {301, 608, 984, 1031, 1051, 98, 118, 0, 55},
                {356, 663, 1039, 1086, 1106, 143, 163, 55, 0}
        };
        std::vector<std::string> Cities3 = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};

        Path path1 = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
        REQUIRE(getPathDistance(path1, Cities3, map3) == getPathDistance_sol(path1, Cities3, map3));

        Path path2 = {"A", "B", "C", "D", "E", "F", "G", "H"};
        REQUIRE(getPathDistance(path2, Cities3, map3) == getPathDistance_sol(path2, Cities3, map3));

        Path path3 = {"A", "B", "C", "D", "E", "F", "G"};
        REQUIRE(getPathDistance(path3, Cities3, map3) == getPathDistance_sol(path3, Cities3, map3));

        Path path4 = {"A", "B", "C", "D", "E", "F"};
        REQUIRE(getPathDistance(path4, Cities3, map3) == getPathDistance_sol(path4, Cities3, map3));

        Path path5 = {"A", "B", "C", "D", "E"};
        REQUIRE(getPathDistance(path5, Cities3, map3) == getPathDistance_sol(path5, Cities3, map3));

        Path path6 = {"A", "B", "C", "D"};
        REQUIRE(getPathDistance(path6, Cities3, map3) == getPathDistance_sol(path6, Cities3, map3));

        Path path7 = {"A", "B", "C"};
        REQUIRE(getPathDistance(path7, Cities3, map3) == getPathDistance_sol(path7, Cities3, map3));
    }
}

int distance_sol(const std::string& city1,const std::string& city2, const std::vector<std::string>& cities, const
Matrix&
map){
    int city1_index = 0;
    int city2_index = 0;
    for (int i = 0; i < cities.size(); i++){
        if (cities[i] == city1){
            city1_index = i;
        }
        if (cities[i] == city2){
            city2_index = i;
        }
    }
    return map[city1_index][city2_index];
}


int getPathDistance_sol(const std::vector<std::string> &path, const std::vector<std::string>& cities, const Matrix&
map){
    int total_distance = 0;
    for (int i = 0; i < path.size() - 1; i++){
        total_distance += distance(path[i], path[i+1], cities, map);
    }
    return total_distance;
}
