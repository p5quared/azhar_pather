//
// Created by Peter Vaiciulis on 3/23/23.
//

#ifndef AZHAR_PATH_MEASURINGDISTANCES_HELPERS_H
#define AZHAR_PATH_MEASURINGDISTANCES_HELPERS_H
#include <vector>
#include <string>

using Matrix = std::vector<std::vector<int>>;
// THESE TWO FUNCTIONS MUST BE IMPLEMENTED:
int distance(int city1, int city2,const Matrix& map);
int pathDistance(const std::vector<int> path, const Matrix& map);

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
#endif //AZHAR_PATH_MEASURINGDISTANCES_HELPERS_H
