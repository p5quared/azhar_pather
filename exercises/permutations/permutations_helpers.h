//
// Created by Peter Vaiciulis on 3/23/23.
//

#ifndef AZHAR_PATH_PERMUTATIONS_HELPERS_H
#define AZHAR_PATH_PERMUTATIONS_HELPERS_H

// THIS FUNCTION MUST BE IMPLEMENTED
template<typename T>
std::vector<std::vector<T>> permutations(std::vector<T> items);

template <typename T>
std::vector<std::vector<T>> permutations(std::vector<T> items) {
    std::vector<std::vector<T>> result;
    if (items.empty()) {
        return result;
    }
    std::sort(items.begin(), items.end());
    do {
        result.push_back(items);
    } while (std::next_permutation(items.begin(), items.end()));
    return result;
}
#endif //AZHAR_PATH_PERMUTATIONS_HELPERS_H
