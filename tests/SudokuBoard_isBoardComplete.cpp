#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "SudokuBoard.hpp"


TEST_CASE("Checking if isValidVertical works") {
    SudokuBoard nonFilled;
    nonFilled.sudokuBoard = {
        {5, 3, 0,   6, 7, 8,   9, 1, 2},
        {6, 7, 2,   1, 9, 5,   3, 4, 8},
        {1, 9, 8,   3, 4, 2,   5, 6, 7},

        {8, 5, 9,   7, 6, 1,   4, 2, 3},
        {4, 2, 6,   8, 5, 3,   7, 9, 1},
        {7, 1, 3,   9, 2, 4,   8, 5, 6},

        {9, 6, 1,   5, 3, 7,   2, 8, 0},
        {2, 8, 7,   4, 1, 9,   6, 3, 5},
        {3, 4, 5,   2, 8, 6,   1, 7, 9}
    };
    CHECK(nonFilled.isBoardComplete() == false);

    SudokuBoard invalidVertical;
    invalidVertical.sudokuBoard = {
        {5, 3, 4,   6, 7, 8,   9, 1, 2},
        {6, 7, 2,   1, 9, 5,   3, 4, 8},
        {1, 9, 8,   3, 4, 2,   5, 6, 7},

        {8, 5, 9,   7, 6, 1,   4, 2, 3},
        {4, 2, 6,   8, 5, 3,   7, 9, 1},
        {7, 1, 3,   9, 2, 4,   8, 5, 6},

        {9, 6, 1,   5, 3, 7,   2, 8, 4},
        {2, 8, 7,   4, 1, 9,   6, 3, 5},
        {3, 4, 5,   2, 8, 6,   1, 7, 1}
    };
    CHECK(invalidVertical.isBoardComplete() == false);

    SudokuBoard invalidHorizontal;
    invalidHorizontal.sudokuBoard = {
        {5, 3, 4,   6, 7, 8,   9, 1, 2},
        {6, 7, 2,   1, 9, 5,   3, 4, 8},
        {1, 9, 8,   3, 4, 2,   5, 6, 7},

        {8, 5, 9,   7, 6, 1,   4, 2, 3},
        {4, 2, 6,   8, 5, 3,   7, 9, 1},
        {7, 1, 3,   9, 2, 4,   8, 5, 6},

        {9, 6, 1,   5, 3, 7,   2, 8, 4},
        {2, 8, 7,   4, 1, 9,   6, 3, 5},
        {3, 4, 5,   2, 8, 6,   1, 1, 9}
    };
    CHECK(invalidHorizontal.isBoardComplete() == false);

    SudokuBoard invalidBlock;
    invalidBlock.sudokuBoard = {
        {5, 3, 4,   6, 7, 8,   9, 1, 2},
        {6, 7, 2,   1, 9, 5,   3, 4, 8},
        {1, 9, 8,   3, 4, 2,   5, 6, 7},

        {8, 5, 9,   7, 6, 1,   4, 2, 3},
        {4, 2, 6,   8, 5, 3,   7, 9, 1},
        {7, 1, 3,   9, 2, 4,   8, 5, 6},

        {9, 6, 1,   5, 3, 7,   2, 8, 4},
        {2, 8, 7,   4, 1, 9,   6, 3, 5},
        {3, 4, 5,   2, 8, 6,   1, 7, 5}
    };
    CHECK(invalidBlock.isBoardComplete() == false);

    SudokuBoard goodBoard;
    goodBoard.sudokuBoard = {
        {5, 3, 4,   6, 7, 8,   9, 1, 2},
        {6, 7, 2,   1, 9, 5,   3, 4, 8},
        {1, 9, 8,   3, 4, 2,   5, 6, 7},

        {8, 5, 9,   7, 6, 1,   4, 2, 3},
        {4, 2, 6,   8, 5, 3,   7, 9, 1},
        {7, 1, 3,   9, 2, 4,   8, 5, 6},

        {9, 6, 1,   5, 3, 7,   2, 8, 4},
        {2, 8, 7,   4, 1, 9,   6, 3, 5},
        {3, 4, 5,   2, 8, 6,   1, 7, 9}
    };
    CHECK(goodBoard.isBoardComplete() == true);
}