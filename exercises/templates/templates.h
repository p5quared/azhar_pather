//
// Created by Peter Vaiciulis on 4/4/23.
//
#include <vector>


/* Testing Info:
 *
 * Name: templates
 * Tags: [easy], [medium], [hard], "<function-name>" (e.g. "sum" or [easy])
 * ex: ./templates "greatest"
 */

/* The goal of these exercises is to practice using templates.
 *
 * Templates are a powerful tool that allows us to write generic code that can be used with different types.
 * */


/*******EASY********/


// Implement a function that returns the sum of two values.
// the function MUST be called sum, and take two parameters.
template <typename T>
T sum(T a, T b) {
    return a + b;
}


// Implement a function that returns the greater of two values.
// the function MUST be called greatest, and take two parameters.
template <typename T>
T greatest(T a, T b) {
    return a > b ? a : b;
}


/********MEDIUM********/


// Implement a function that returns the sum of all values in a vector.
// the function MUST be called sum_vector, and it MUST be a template function.
template <typename T>
T sum_vector(std::vector<T> vec) {
    T sum = vec.at(0);
    for (size_t i = 1; i < vec.size(); i++) {
        sum += vec.at(i);
    }
    return sum;
}

/********HARD********/

// Implement a function that returns the dot product of two vectors (math/physics vectors, not std::vector).
// (https://en.wikipedia.org/wiki/Dot_product)
// The function MUST be called dot_product, and take two parameters, two arrays representing the vectors.
// implement WITHOUT passing a size parameter to the function.
template<typename T, size_t N>
T dotProduct(const T (&a)[N], const T (&b)[N]) {
    T result = 0;
    for (size_t i = 0; i < N; i++) {
        result += a[i] * b[i];
    }
    return result;
}