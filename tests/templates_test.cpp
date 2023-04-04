//
// Created by Peter Vaiciulis on 4/4/23.
//
#include <vector>
#include <string>
#include <catch2/catch_test_macros.hpp>

#include "templates/templates.h"

TEST_CASE("sum"){
    SECTION("Given two ints"){
        REQUIRE(sum(1, 2) == 3);
        REQUIRE(sum(2, 2) == 4);
        REQUIRE(sum(3, 2) == 5);
    }
    SECTION("Given two doubles"){
        REQUIRE(sum(1.0, 2.0) == 3.0);
        REQUIRE(sum(2.0, 2.0) == 4.0);
        REQUIRE(sum(3.0, 2.0) == 5.0);
    }
    SECTION("Given two strings"){
        REQUIRE(sum(std::string("1"), std::string("2")) == std::string("12"));
        REQUIRE(sum(std::string("2"), std::string("2")) == std::string("22"));
        REQUIRE(sum(std::string("3"), std::string("2")) == std::string("32"));
    }
}

TEST_CASE("greatest"){
    SECTION("Given two ints"){
        REQUIRE(greatest(1, 2) == 2);
        REQUIRE(greatest(2, 2) == 2);
        REQUIRE(greatest(3, 2) == 3);
    }
    SECTION("Given two doubles"){
        REQUIRE(greatest(1.0, 2.0) == 2.0);
        REQUIRE(greatest(2.0, 2.0) == 2.0);
        REQUIRE(greatest(3.0, 2.0) == 3.0);
    }
    SECTION("Given two strings"){
        REQUIRE(greatest(std::string("1"), std::string("2")) == std::string("2"));
        REQUIRE(greatest(std::string("2"), std::string("2")) == std::string("2"));
        REQUIRE(greatest(std::string("3"), std::string("2")) == std::string("3"));
    }
}

TEST_CASE("sum_vector"){
    SECTION("Given vector of ints"){
        std::vector<int> v = {1, 2, 3, 4, 5};
        REQUIRE(sum_vector(v) == 15);
    }
    SECTION("Given vector of doubles"){
        std::vector<double> v = {1.0, 2.0, 3.0, 4.0, 5.0};
        REQUIRE(sum_vector(v) == 15.0);
    }
    SECTION("Given vector of strings"){
        std::vector<std::string> v = {"a", "b", "r", "a", "c", "a", "d", "a", "b", "r", "a"};
        REQUIRE(sum_vector(v) == "abracadabra");
    }
}

TEST_CASE("dot_product"){
    SECTION("Given two arrays of ints"){
        int a[] = {1, 2, 3, 4, 5};
        int b[] = {1, 2, 3, 4, 5};
        REQUIRE(dotProduct(a, b) == 55);
    }
    SECTION("Given two arrays of doubles"){
        double a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
        double b[] = {1.0, 2.0, 3.0, 4.0, 5.0};
        REQUIRE(dotProduct(a, b) == 55.0);
    }
    SECTION("Given two arrays of floats"){
        float a[] = {1.0f, 2.0f, 3.0f, -4.0f, 5.0f};
        float b[] = {1.0f, -2.0f, 3.0f, 4.0f, -5.0f};
        REQUIRE(dotProduct(a, b) == -35.0f);
    }
}