//
// Created by Peter Vaiciulis on 3/16/23.
//
#include <vector>
#include <string>
#include <iostream>

using Matrix = std::vector<std::vector<int>>;
using Path = std::vector<std::string>;

/*
 * Now we will bring together all the pieces we have developed so far.
 * We will write a program that can read a Matrix of distances between cities,
 * and then find the shortest and longest path that visits all the cities.
 *
 * For some hints, see the bottom of this file.
 * Use as few hints as possible.
 */

// Example data
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

// Implement this function. Feel free to write as many helper functions as you need.
// This function should return a pair of integers where:
//      first = shortest path distance
//      second = longest path distance
std::pair<int, int> shortestAndLongestPath(const std::vector<std::string>& cities, const Matrix& dist_matrix);

std::vector<std::vector<std::string>> permutePaths(std::vector<std::string> cities);
int distance(const std::string& city1,const std::string& city2, const std::vector<std::string>& cities, const Matrix&
map);
int getPathDistance(const Path &path, const std::vector<std::string>& cities, const Matrix& map);



int main(){

    auto [shorter, longer] = shortestAndLongestPath(Cities, map1);
    std::cout << "Shortest path: " << shorter << std::endl;
    std::cout << "Longest path: " << longer << std::endl;

    auto [shorter2, longer2] = shortestAndLongestPath(Cities2, map2);
    std::cout << "Shortest path: " << shorter2 << std::endl;
    std::cout << "Longest path: " << longer2 << std::endl;


    return 0;

}

std::vector<Path> permutePaths(std::vector<std::string> cities){
    std::vector<std::vector<std::string>> all_paths;
    if (cities.empty()) {
        return all_paths;
    }
    std::sort(cities.begin(), cities.end());
    do {
        all_paths.push_back(cities);
    } while (std::next_permutation(cities.begin(), cities.end()));

    return all_paths;
}

std::pair<int, int> shortestAndLongestPath(const std::vector<std::string>& cities, const Matrix& dist_matrix){
    std::vector<Path> all_paths = permutePaths(cities);
    int shortest_path = 0;
    int longest_path = 0;

    for (auto const path : all_paths) {
        int path_distance = getPathDistance(path, cities, dist_matrix);
        if (shortest_path == 0 || path_distance < shortest_path) {
            shortest_path = path_distance;
        }
        if (longest_path == 0 || path_distance > longest_path) {
            longest_path = path_distance;
        }
    }

    return {shortest_path, longest_path};
}


int distance(const std::string& city1,const std::string& city2, const std::vector<std::string>& cities, const Matrix&
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


int getPathDistance(const std::vector<std::string> &path, const std::vector<std::string>& cities, const Matrix& map){
    int total_distance = 0;
    for (int i = 0; i < path.size() - 1; i++){
        total_distance += distance(path[i], path[i+1], cities, map);
    }
    return total_distance;
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

