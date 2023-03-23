//
// Created by Peter Vaiciulis on 3/16/23.
//
#include <vector>
#include <string>
#include <iostream>
#include "main_helpers.h"

/*
 * Now we will bring together all the pieces we have developed so far.
 * We will write a program that can read a Matrix of distances between cities,
 * and then find the shortest and longest path that visits all the cities.
 *
 * For some hints, see the bottom of this file.
 * Use as few hints as possible.
 */

// Sample data
std::vector<std::string> Cities = {"A", "B", "C", "D"};
Matrix map1 = {
         {0, 40, 20, 90},
         {40, 0, 30, 70},
         {20, 30, 0, 55},
         {90, 70, 55, 0}
};


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



int main(){

    std::cout << "Map 1:\n";
    auto [shorter, longer] = shortestAndLongestPath(Cities, map1);
    std::cout << "Shortest path: " << shorter << std::endl;
    std::cout << "Longest path: " << longer << std::endl;

    std::cout << "Map 2:\n";
    auto [shorter2, longer2] = shortestAndLongestPath(Cities2, map2);
    std::cout << "Shortest path: " << shorter2 << std::endl;
    std::cout << "Longest path: " << longer2 << std::endl;


    return 0;

}



/*
 * Thought Process:
 *
 * 1. We can represent a path as a vector of city names.
 *         We already know how to find the distance between two cities, or any path of cities.
 *
 * 2. To find the shortest path, the simplest approach is to try all possible paths.
 *         This is called brute force search.
 *
 * 3. To try all possible paths, we just need to generate all possible permutations of the city names (all paths).
 *         Then we can just measure the distance of each path and keep the shortest and longest.
 */

