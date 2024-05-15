#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "SudokuBoard.hpp"


TEST_CASE("Checking if isValidHorziontal works") {
    SudokuBoard badBoard;
    badBoard.sudokuBoard = {
        {1, 1, 0,   0, 0, 0,   0, 0, 0},
        {2, 0, 2,   0, 0, 0,   0, 0, 0},
        {3, 0, 0,   3, 0, 0,   0, 0, 0},

        {4, 0, 0,   0, 4, 0,   0, 0, 0},
        {5, 0, 0,   0, 0, 5,   0, 0, 0},
        {6, 0, 0,   0, 0, 0,   6, 0, 0},

        {7, 0, 0,   0, 0, 0,   0, 7, 0},
        {8, 0, 0,   0, 0, 0,   0, 0, 8},
        {9, 9, 0,   0, 0, 0,   0, 0, 0}
    };

    for (int y = 0; y < badBoard.sudokuBoard.size(); y++) {
        CHECK(badBoard.isValidHorizontal(y, 0) == false);
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
        {0, 0, 0,   0, 0, 0,   1, 0, 0}
    };

    CHECK(goodBoard.isValidHorizontal(0, 0) == true);
}