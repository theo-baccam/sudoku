#include <vector>
#include <random>
#include <ctime>
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
    if (this->sudokuBoard[y][x] == 0) {
        return true;
    };

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
    if (this->sudokuBoard[y][x] == 0) {
        return true;
    };

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
    if (this->sudokuBoard[y][x] == 0) {
        return true;
    };

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

void SudokuBoard::generateBoard(double densityFraction) {
    srand(time(0));
    int maxFilledSquares = (9 * 9) * densityFraction;

    int i = 0;
    int j = 0;
    do {
        int randomY = rand() % 9;
        int randomX = rand() % 9;
        int randomValue = rand() % 9 + 1;

        if (this->sudokuBoard[randomY][randomX] != 0) {
            continue;
        };
        this->sudokuBoard[randomY][randomX] = randomValue;

        if (!(
            (isValidHorizontal(randomY, randomX)) &&
            (isValidVertical(randomY, randomX)) &&
            (isValidBlock(randomY, randomX))
        )) {
            this->sudokuBoard[randomY][randomX] = 0;
            continue;
        };

        j = 0;
        for (int y = 0; y < this->sudokuBoard.size(); y++) {
            for (int x = 0; x < this->sudokuBoard[y].size(); x++) {
                if (sudokuBoard[y][x] == randomValue) j++;
            };
        };
        if (j > 9) {
            this->sudokuBoard[randomY][randomX] = 0;
            continue;
        };

        i++;
    } while (i != maxFilledSquares);
}