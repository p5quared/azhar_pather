//
// Created by Peter Vaiciulis on 3/16/23.
//

#include <vector>
#include <catch2/catch_test_macros.hpp>

#include "permutations.cpp"

TEST_CASE("Vector of Integers")
{
    SECTION("Empty Vector")
    {
        std::vector<int> items = {};
        std::vector<std::vector<int>> expected = {};
        REQUIRE(permutations<int>(items) == expected);
    }
    SECTION("Example1"){
        std::vector<int> items = {1, 2, 3};
        std::vector<std::vector<int>> expected = {
                {1, 2, 3},
                {1, 3, 2},
                {2, 1, 3},
                {2, 3, 1},
                {3, 1, 2},
                {3, 2, 1}
        };
        REQUIRE(permutations<int>(items) == expected);
    }
    SECTION("Example2"){
        std::vector<int> five_elements = {1, 2, 3, 4, 5};
        REQUIRE(permutations(five_elements).size() == 120);
    }

    SECTION("Big Vector of Ints") {
        std::vector<int> items;
        for (int i = 0; i < 10; i++) {
            items.push_back(i);
        }
        REQUIRE(permutations<int>(items).size() == 3628800);
    }
}

TEST_CASE("Vector of Chars")
{
    SECTION("Empty Vector")
    {
        std::vector<char> items = {};
        std::vector<std::vector<char>> expected = {};
        REQUIRE(permutations<char>(items) == expected);
    }
    SECTION("Example1"){
        std::vector<char> items = {'a', 'b', 'c'};
        std::vector<std::vector<char>> expected = {
                {'a', 'b', 'c'},
                {'a', 'c', 'b'},
                {'b', 'a', 'c'},
                {'b', 'c', 'a'},
                {'c', 'a', 'b'},
                {'c', 'b', 'a'}
        };
        REQUIRE(permutations<char>(items) == expected);
    }
    SECTION("Example2"){
        std::vector<char> five_elements = {'a', 'b', 'c', 'd', 'e'};
        REQUIRE(permutations<char>(five_elements).size() == 120);
    }

    SECTION("Big Vector of Chars") {
        std::vector<char> items;
        for (int i = 0; i < 10; i++) {
            items.push_back('a' + i);
        }
        REQUIRE(permutations<char>(items).size() == 3628800);
    }
}

TEST_CASE("Vector of City Names")
{
    SECTION("Empty Vector")
    {
        std::vector<std::string> items = {};
        std::vector<std::vector<std::string>> expected = {};
        REQUIRE(permutations<std::string>(items) == expected);
    }
    SECTION("Example1"){
        std::vector<std::string> items = {"Vilnius", "Kaunas", "Klaipeda"};
        std::sort(items.begin(), items.end());
        std::vector<std::vector<std::string>> expected = {
                {"Kaunas", "Klaipeda", "Vilnius"},
                {"Kaunas", "Vilnius", "Klaipeda"},
                {"Klaipeda", "Kaunas", "Vilnius"},
                {"Klaipeda", "Vilnius", "Kaunas"},
                {"Vilnius", "Kaunas", "Klaipeda"},
                {"Vilnius", "Klaipeda", "Kaunas"}
        };
        REQUIRE(permutations<std::string>(items) == expected);
    }
    SECTION("Example2"){
        std::vector<std::string> five_elements = {"Vilnius", "Kaunas", "Klaipeda", "Siauliai", "Panevezys"};
        REQUIRE(permutations<std::string>(five_elements).size() == 120);
    }

    SECTION("Big Vector of City Names") {
        std::vector<std::string> items;
        for (int i = 0; i < 10; i++) {
            items.push_back("City" + std::to_string(i));
        }
        std::sort(items.begin(), items.end());
        REQUIRE(permutations<std::string>(items).size() == 3628800);
    }
}