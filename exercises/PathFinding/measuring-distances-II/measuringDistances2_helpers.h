//
// Created by Peter Vaiciulis on 3/23/23.
//


#pragma once
#include <vector>
#include <string>

/*
 * Just as we defined Matrix in part1, we can define Path as a vector of integers or strings.
 * It is very common in C++ to use type aliasing feature.
 *
 * Try not to overdo it though; we are using it here mostly for the purpose of demonstration.
 */
using Path = std::vector<std::string>;
using Matrix = std::vector<std::vector<int>>;

/*
 * Accessing cities by their index is not very intuitive, especially for users of our program.
 * We can improve the usability of our program by using strings to represent the cities.
 * For example, instead of using the index 0 to represent the city "A", we can use the string "A".
 * This way, when we call the distance function, we can pass in the strings "A" and "B" instead of 0 and 1.
 * This makes our program more readable and easier to use.
 *
 * The problem is that we can't use strings as indices in a matrix.
 * We need a way to convert the strings to integers, and vice versa.
 */
std::vector<std::string> Cities = {"A", "B", "C", "D"};
Matrix map1 = {
        {0, 10, 20, 30},
        {10, 0, 40, 50},
        {20, 40, 0, 60},
        {30, 50, 60, 0}
};

std::vector<std::string> Cities2 = {"New York", "Chicago", "Los Angeles", "Houston"};
Matrix map2 = {
        {0, 99, 1234, 83},
        {99, 0, 123, 123},
        {1234, 123, 0, 123},
        {83, 123, 123, 0}
};

/*
 * The goal of this exercise is to allow our users to use strings to represent the cities.
 * Try to reuse the functions you wrote in the previous exercises, but modify them, or use helper functions,
 * so we can use strings instead of integers.
 */
// BOTH OF THESE FUNCTIONS MUST BE IMPLEMENTED
int distance(const std::string& city1,const std::string& city2, const std::vector<std::string>& cities, const Matrix&
map);
int getPathDistance(const std::vector<std::string> &path, const std::vector<std::string>& cities, const Matrix& map);


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
