//
// Created by Peter Vaiciulis on 3/23/23.
//

#ifndef AZHAR_PATH_MAIN_HELPERS_H
#define AZHAR_PATH_MAIN_HELPERS_H

#include <vector>
#include <string>

using Matrix = std::vector<std::vector<int>>;
using Path = std::vector<std::string>;

// YOU MUST IMPLEMENT THIS FUNCTION:
std::pair<int, int> shortestAndLongestPath(const std::vector<std::string>& cities, const Matrix& dist_matrix);

// You can create more helper functions as you please.
std::vector<std::vector<std::string>> permutePaths(std::vector<std::string> cities);
int distance(const std::string& city1,const std::string& city2, const std::vector<std::string>& cities, const Matrix&
map);
int getPathDistance(const Path &path, const std::vector<std::string>& cities, const Matrix& map);


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
#endif //AZHAR_PATH_MAIN_HELPERS_H
