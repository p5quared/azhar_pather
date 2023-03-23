//
// Created by Peter Vaiciulis on 3/16/23.
//

#include <vector>
#include <iostream>

/*
 * Permutations are a sequence of elements that can be rearranged in a number of ways.
 * For example, the word "hat" has 6 permutations: "hat", "hta", "aht", "ath", "tha", "tah".
 * The number of permutations of a set of n elements is n! (n factorial).
 */

/*
 * Write a definition for the function permutations that takes a vector of items of type T,
 * and returns a vector of vectors of items of type T. The returned vector should contain
 * all possible permutations of the input vector.
 * */
template<typename T>
std::vector<std::vector<T>> permutations(std::vector<T> items);


int main() {

    return 0;
}



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


