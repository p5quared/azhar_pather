//
// Created by Peter Vaiciulis on 3/16/23.
//

#include <vector>
#include <iostream>

/*
 * One way we can represent the distances between cities is with a matrix.
 * The matrix is a 2D array of integers, where the rows and columns represent the cities.
 * The value at row i and column j represents the distance between city i and city j.
 *
 * For example, the following matrix represents the distances between 4 cities:
 * [0, 1, 2, 3]
 * [1, 0, 4, 5]
 * [2, 4, 0, 6]
 * [3, 5, 6, 0]
 *
 * The distance between city 0 and city 1 is 1.
 * The distance between city 1 and city 2 is 4.
 * ...
 *
 * We can think of each row as a "starting point", and each column as an "ending point".
 * So the first row represents the distance between city 0 and all other cities.
 */

// From now on we will use the type Matrix to represent a 2D array of distance
using Matrix = std::vector<std::vector<int>>;

Matrix map1 = {
        {0, 10, 20, 30},
        {10, 0, 40, 50},
        {20, 40, 0, 60},
        {30, 50, 60, 0}
};

Matrix map2 = {
        {0, 99, 1234, 83},
        {99, 0, 123, 123},
        {1234, 123, 0, 123},
        {83, 123, 123, 0}
};



/*
 * Your first goal for this exercise is to write a function that returns the distance between two cities.
 * The function should take two integers as parameters, representing the indices of the cities.
 * The function should return an integer representing the distance between the two cities.
 *
 * Use the already declared distance function.
 */
int distance(int city1, int city2,const Matrix& map);

/*
 * Your second goal for this exercise is to write a function that can calculate the distance of a path.
 * The function should take a vector of integers as a parameter, representing the indices of the cities.
 * The function should return an integer representing the distance of the path.
 * The distance of a path is the sum of the distance between each city in the path.
 */
int pathDistance(const std::vector<int> path, const Matrix& map);



int main(){
    return 0;
}



int distance(int city1, int city2, const Matrix& map) {
    return map[city1][city2];
}

int pathDistance(const std::vector<int> path, const Matrix& map) {
    int total_distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        total_distance += distance(path[i], path[i + 1], map);
    }
    return total_distance;
}
