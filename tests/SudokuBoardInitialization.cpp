#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "SudokuBoard.hpp"


TEST_CASE("Checking if SudokuBoard is initialized properly") {
    SudokuBoard board;

    CHECK(board.sudokuBoard.size() == 9);
    for (int i = 0; i < board.sudokuBoard.size(); i++) {
        CHECK(board.sudokuBoard[i].size() == 9);
    };
}