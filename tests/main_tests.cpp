//
// Created by Peter Vaiciulis on 3/16/23.
//

#include <vector>
#include <string>
#include <catch2/catch_test_macros.hpp>

#include "main_helpers.h"

TEST_CASE("shortestAndLongestPath"){
    SECTION("Given Map1"){
        std::vector<std::string> Cities = {"A", "B", "C", "D"};
        Matrix map1 = {
                {0, 40, 20, 90},
                {40, 0, 30, 70},
                {20, 30, 0, 55},
                {90, 70, 55, 0}
        };
        const auto [shorter, longer] = shortestAndLongestPath(Cities, map1);
        REQUIRE(shorter == 115);
        REQUIRE(longer == 190);
    }

    SECTION("Given Map2"){
        std::vector<std::string> Cities2 = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
        Matrix map2 = {
                {0, 991, 1558, 1004, 941, 1398, 1318, 1743, 1719},
                {991, 0, 590, 557, 659, 890, 966, 1198, 1241},
                {1558, 590, 0, 556, 714, 490, 746, 616, 796},
                {1004, 557, 556, 0, 165, 397, 445, 743, 718},
                {941, 659, 714, 165, 0, 478, 365, 814, 789},
                {1398, 890, 490, 397, 478, 0, 291, 327, 317},
                {1318, 966, 746, 445, 365, 291, 0, 632, 545},
                {1743, 1198, 616, 743, 814, 327, 632, 0, 301},
                {1719, 1241, 796, 718, 789, 317, 545, 301, 0}
        };

        const auto [shorter, longer] = shortestAndLongestPath(Cities2, map2);
        REQUIRE(shorter == 3576);
        REQUIRE(longer == 8350);
    }

    SECTION("Extra Maps"){
        // map of 3 cities
        std::vector<std::string> Cities = {"A", "B", "C"};
        Matrix map = {
                {0, 10, 20},
                {10, 0, 30},
                {20, 30, 0}
        };

        const auto [shorter, longer] = shortestAndLongestPath(Cities, map);
        REQUIRE(shorter == 30);
        REQUIRE(longer == 50);

        SECTION("Map of Length 10 - 1"){
            std::vector<std::string> Cities5 = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
            std::vector<std::vector<int>> map5 = {
                    {0, 415, 456, 233, 179, 894, 859, 754, 719, 571},
                    {415, 0, 907, 236, 869, 406, 735, 274, 235, 827},
                    {456, 907, 0, 428, 566, 925, 526, 568, 972, 225},
                    {233, 236, 428, 0, 234, 232, 512, 676, 474, 369},
                    {179, 869, 566, 234, 0, 252, 721, 801, 581, 454},
                    {894, 406, 925, 232, 252, 0, 195, 254, 133, 244},
                    {859, 735, 526, 512, 721, 195, 0, 457, 652, 245},
                    {754, 274, 568, 676, 801, 254, 457, 0, 232, 165},
                    {719, 235, 972, 474, 581, 133, 652, 232, 0, 247},
                    {571, 827, 225, 369, 454, 244, 245, 165, 247, 0}
            };
            const auto [shorter, longer] = shortestAndLongestPath(Cities5, map5);

            REQUIRE(shorter == 1952);
            REQUIRE(longer == 7335);
        }
        SECTION("Map of Length 11"){
            std::vector<std::string> Cities4 = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
            std::vector<std::vector<int>> map4= {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                                 {1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                                                 {2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8},
                                                 {3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7},
                                                 {4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6},
                                                 {5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5},
                                                 {6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4},
                                                 {7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3},
                                                 {8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2},
                                                 {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1},
                                                 {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};
            const auto [shorter, longer] = shortestAndLongestPath(Cities4, map4);
            REQUIRE(shorter == 10);
            REQUIRE(longer == 59);
        }
        SECTION("Map of Length 10 - 2"){
            std::vector<std::string> Cities = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
            std::vector<std::vector<int>> map = {
                                                         {0, 355, 435, 272, 201, 216, 146, 416, 461, 430},
                                                         {355, 0, 374, 331, 372, 470, 468, 288, 202, 313},
                                                         {435, 374, 0, 438, 101, 235, 180, 310, 428, 189},
                                                         {272, 331, 438, 0, 443, 318, 326, 261, 277, 160},
                                                         {201, 372, 101, 443, 0, 129, 491, 311, 154, 345},
                                                         {216, 470, 235, 318, 129, 0, 169, 426, 384, 492},
                                                         {146, 468, 180, 326, 491, 169, 0, 205, 371, 308},
                                                         {416, 288, 310, 261, 311, 426, 205, 0, 280, 243},
                                                         {461, 202, 428, 277, 154, 384, 371, 280, 0, 484},
                                                         {430, 313, 189, 160, 345, 492, 308, 243, 484, 0}
                                                 };
            const auto [shorter, longer] = shortestAndLongestPath(Cities, map);

            REQUIRE(shorter == 1625);
            REQUIRE(longer == 4163);
        }
    }

}