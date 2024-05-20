#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "SudokuBoard.hpp"


TEST_CASE("Checking if generateBoard works") {
    SudokuBoard randomBoard;
    randomBoard.generateBoard(0.25);

    for (int y = 0; y < randomBoard.sudokuBoard.size(); y++) {
        for (int x = 0; x < randomBoard.sudokuBoard[y].size(); x++) {
            CHECK(randomBoard.isValidHorizontal(y, x) == true);
            CHECK(randomBoard.isValidVertical(y, x) == true);
            CHECK(randomBoard.isValidBlock(y, x) == true);
        };
    };
}