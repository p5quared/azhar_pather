#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//#include <time.h>
using Path = std::vector<char>;
using City = char;
using Distance = long;

/*
 *  Each distance is formed by adding the distance between each city in the path where
 *  ABCD is the path A->B->C->D
 *  a = 0, b = 1, c = 2, d = 3
 *  a->b  is the distance from city a to city b represented by
 *  distance_matrix[0][1] = 40
 *  b->c  is the distance from city b to city c represented by
 *  distance_matrix[1][2] = 30
 *  c->d  is the distance from city c to city d represented by
 *  distance_matrix[2][3] = 55
 *
 *  distance_matrix[0][1] + distance_matrix[1][2] + distance_matrix[2][3] = 125
 *
 *  Phrased differently, we are summing the 2-permutations of A B C D.
 * */

//const int NUM_CITIES = 4;
//char cityNames[] = {'A', 'B', 'C', 'D'};
//int map1[NUM_CITIES][NUM_CITIES] ={
//         {0, 40, 20, 90},
//         {40, 0, 30, 70},
//         {20, 30, 0, 55},
//         {90, 70, 55, 0}};


const int NUM_CITIES = 9;
char cityNames[] = {'A','B','C','D','E','F','G','H','I'};
int map1[NUM_CITIES][NUM_CITIES] =
        {{0, 991, 1558, 1004, 941, 1398, 1318, 1743, 1719},
         {991, 0, 590, 557, 659, 890, 966, 1198, 1241},
         {1558, 590, 0, 556, 714, 490, 746, 616, 796},
         {1004, 557, 556, 0, 165, 397, 445, 743, 718},
         {941, 659, 714, 165, 0, 478, 365, 814, 789},
         {1398, 890, 490, 397, 478, 0, 291, 327, 317},
         {1318, 966, 746, 445, 365, 291, 0, 632, 545},
         {1743, 1198, 616, 743, 814, 327, 632, 0, 301},
         {1719, 1241, 796, 718, 789, 317, 545, 301, 0}};


//int factorial(int n);
//char* getPaths(const char[], int[], int[][NUM_CITIES], int, int);
std::vector<Path> permuteCityNames(const char city_names[], int number_of_cities);
std::map<City, int> getCityKeys(const char city_names[], int number_of_cities);
long getDistance(Path path, int distance_matrix[][NUM_CITIES], std::map<char, int> city_key);

int main (void) {
    // for additional fun:
//    std::clock_t tStart = clock();

    std::vector<Path> allPaths = permuteCityNames(cityNames, NUM_CITIES);
    std::map<City, int> city_key = getCityKeys(cityNames, NUM_CITIES);

    std::pair<Path, Distance> firstPath = std::make_pair(allPaths[0], getDistance(allPaths[0], map1,
                                                                                  city_key));
    std::pair<Path, Distance> shortestPath = firstPath;
    std::pair<Path, Distance> longestPath = firstPath;

    std::cout << "All possible paths: " << std::endl;
    for (const auto path : allPaths) {
        for (const auto city : path) {
            std::cout << city << " ";
        }
        int distance = getDistance(path, map1, city_key);
        std::cout << distance << std::endl;
        if (distance < shortestPath.second) {
            shortestPath = std::make_pair(path, distance);
        }
        if (distance > longestPath.second) {
            longestPath = std::make_pair(path, distance);
        }
    }

    std::cout << "\nThe shortest path is: " << std::endl;
    for (const auto city : shortestPath.first) {
        std::cout << city << " ";
    }
    std::cout << "with distance: " << shortestPath.second << std::endl;

    std::cout << "The longest path is: " << std::endl;
    for (const auto city : longestPath.first) {
        std::cout << city << " ";
    }
    std::cout << "with distance: " << longestPath.second << std::endl;
//    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


    return 0;
}

// Returns a vector of all possible paths (A->B->C->D)
// Example: A B C D, A B D C, A C B D, ... , D C B A
std::vector<Path> permuteCityNames(const char city_names[], int number_of_cities) {
    std::vector<Path> allPaths;
    Path path;
    for (int i=0; i < number_of_cities; i++)
        path.push_back(city_names[i]);

    do {
        allPaths.push_back(path);
    } while ( next_permutation(path.begin(), path.end()) );

    return allPaths;
}

// Returns a map of characters to integers representing the mapping of city names to indices
// The indices are used to access the distance matrix
// Example: city_key['A'] = 0, city_key['B'] = 1, etc...
std::map<City, int> getCityKeys(const char city_names[], int number_of_cities) {
    std::map<City, int> city_key;
    for (int i=0; i < number_of_cities; i++)
        city_key[city_names[i]] = i;
    return city_key;
}

// Given a path between cities (A->B->C->D), returns the total distance of the path by summing
// the distance between each city
// Example: A B C D, returns distance_matrix[0][1] + distance_matrix[1][2] + distance_matrix[2][3]
long getDistance(Path path, int distance_matrix[][NUM_CITIES], std::map<City, int> city_key) {
    long distance = 0;
    for (int i=0; i < path.size() - 1; i++) {
        int a = city_key[path[i]];
        int b = city_key[path[i+1]];
        distance += distance_matrix[a][b];
    }
    return distance;
}
