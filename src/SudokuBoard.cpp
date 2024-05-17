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

bool SudokuBoard::isValidVertical(int y, int x) {
    for (int _y = 0; _y < this->sudokuBoard.size(); _y++) {
        if (_y == y) {
            continue;
        };

        if (this->sudokuBoard[_y][x] == this->sudokuBoard[y][x]) {
            return false;
        };
    };

    return true;
}

bool SudokuBoard::isValidBlock(int y, int x) {
    int blockY = y - y % 3;
    int blockX = x - x % 3;
    for (int _y = 0; _y < 3; _y++) {
        for (int _x = 0; _x < 3; _x++) {
            if (
                ((_y + blockY) == y) &&
                ((_x + blockX) == x)
            ) {
                continue;
            }
            if (
                this->sudokuBoard[_y + blockY][_x + blockX]
                == this->sudokuBoard[y][x]
            ) {
                return false;
            };
        };
    };

    return true;
}

bool SudokuBoard::isBoardComplete() {
    for (int y = 0; y < this->sudokuBoard.size(); y++) {
        for (int x = 0; x < this->sudokuBoard[y].size(); x++) {
            if (this->sudokuBoard[y][x] == 0) {
                return false;
            } else if (!isValidHorizontal(y, x)) {
                return false;
            } else if (!isValidVertical(y, x)) {
                return false;
            } else if (!isValidBlock(y, x)) {
                return false;
            };
        };
    };

    return true;
}