#include <vector>
#include "SudokuBoard.hpp"


SudokuBoard::SudokuBoard() {
    this->sudokuBoard = {
        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},

        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},

        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0},
        {0, 0, 0,   0, 0, 0,   0, 0, 0}
    };
}
SudokuBoard::~SudokuBoard() {}

bool SudokuBoard::isValidHorizontal(int y, int x) {
    for (int _x = 0; _x < this->sudokuBoard[y].size(); _x++) {
        if (_x == x) {
            continue;
        };

        if (this->sudokuBoard[y][_x] == this->sudokuBoard[y][x]) {
            return false;
        };
    };

    return true;
}