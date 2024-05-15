#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "SudokuBoard.hpp"


TEST_CASE("Checking if isValidVertical works") {
    SudokuBoard badBoard;
    badBoard.sudokuBoard = {
        {1, 2, 3,   4, 5, 6,   7, 8, 9},
        {1, 0, 0,   0, 0, 0,   0, 0, 9},
        {0, 2, 0,   0, 0, 0,   0, 0, 0},

        {0, 0, 3,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   4, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 5, 0,   0, 0, 0},

        {0, 0, 0,   0, 0, 6,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   7, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 8, 0}
    };

    for (int x = 0; x < badBoard.sudokuBoard.size(); x++) {
        CHECK(badBoard.isValidVertical(0, x) == false);
    };

    SudokuBoard goodBoard;
    goodBoard.sudokuBoard = {
        {1, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},

        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},

        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 1}
    };

    CHECK(goodBoard.isValidHorizontal(0, 0) == true);
}