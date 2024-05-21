#include <vector>
#include <random>
#include <ctime>
#include "SudokuBoard.hpp"


// Constructor of the SudokuBoard class
SudokuBoard::SudokuBoard() {
    // Initialize the board with 0s
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
    // Copy the initial state of the Sudoku board to originalBoard
    this->originalBoard = sudokuBoard;
}

// Destructor of the SudokuBoard class
SudokuBoard::~SudokuBoard() {}

// Check if the number in the given cell is unique in its row
bool SudokuBoard::isValidHorizontal(int y, int x) {
    // If the cell is empty, it's valid
    if (this->sudokuBoard[y][x] == 0) {
        return true;
    };

    // Check all other cells in the same row
    for (int _x = 0; _x < this->sudokuBoard[y].size(); _x++) {
        // Skip the cell itself
        if (_x == x) {
            continue;
        };

        // If another cell in the same row has the same number, it's not valid
        if (this->sudokuBoard[y][_x] == this->sudokuBoard[y][x]) {
            return false;
        };
    };

    // If no other cell in the same row has the same number, it's valid
    return true;
}

// Check if the number in the given cell is unique in its column
bool SudokuBoard::isValidVertical(int y, int x) {
    // If the cell is empty, it's valid
    if (this->sudokuBoard[y][x] == 0) {
        return true;
    };

    // Check all other cells in the same column
    for (int _y = 0; _y < this->sudokuBoard.size(); _y++) {
        // Skip the cell itself
        if (_y == y) {
            continue;
        };

 // If another cell in the same column has the same number, it's not valid
        if (this->sudokuBoard[_y][x] == this->sudokuBoard[y][x]) {
            return false;
        };
    };

// If no other cell in the same column has the same number, it's valid
    return true;
}

// Check if the number in the given cell is unique in its 3x3 block
bool SudokuBoard::isValidBlock(int y, int x) {
    // If the cell is empty, it's valid
    if (this->sudokuBoard[y][x] == 0) {
        return true;
    };

// Calculate the top-left corner of the 3x3 block
    int blockY = y - y % 3;
    int blockX = x - x % 3;

    // Check all other cells in the same 3x3 block
    for (int _y = 0; _y < 3; _y++) {
        for (int _x = 0; _x < 3; _x++) {
            // Skip the cell itself
            if (
                ((_y + blockY) == y) &&
                ((_x + blockX) == x)
            ) {
                continue;
            }
             // If another cell in the same 3x3 block has the same number, it's not valid
            if (
                this->sudokuBoard[_y + blockY][_x + blockX]
                == this->sudokuBoard[y][x]
            ) {

                // If no other cell in the same 3x3 block has the same number, it's valid
                return false;
            };
        };
    };

    return true;
}

// Check if the Sudoku board is complete and valid
bool SudokuBoard::isBoardComplete() {
    // Check all cells
    for (int y = 0; y < this->sudokuBoard.size(); y++) {
         // If a cell is empty or not valid, the board is not complete
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

// If all cells are filled and valid, the board is complete
    return true;
}

// Generate a Sudoku board with a given density of filled cells
void SudokuBoard::generateBoard(double densityFraction) {
     // Initialize the random number generator
     srand(time(0));

     // Calculate the maximum number of filled cells
    int maxFilledSquares = (9 * 9) * densityFraction;

    int i = 0;
    int j = 0;
    do {

        // Generate random coordinates and a random number
        int randomY = rand() % 9;
        int randomX = rand() % 9;
        int randomValue = rand() % 9 + 1;

        // If the cell is already filled, skip it
        if (this->sudokuBoard[randomY][randomX] != 0) {
            continue;
        };

        // Fill the cell with the random number
        this->sudokuBoard[randomY][randomX] = randomValue;

        // If the number is not valid in the row, column, or block, remove it
        if (!(
            (isValidHorizontal(randomY, randomX)) &&
            (isValidVertical(randomY, randomX)) &&
            (isValidBlock(randomY, randomX))
        )) {
            this->sudokuBoard[randomY][randomX] = 0;
            continue;
        };

        j = 0;
        // Count the occurrences of the random number
        for (int y = 0; y < this->sudokuBoard.size(); y++) {
            for (int x = 0; x < this->sudokuBoard[y].size(); x++) {
                if (sudokuBoard[y][x] == randomValue) j++;
            };
        };
        // If the random number occurs more than 9 times, empty the cell and skip it
        if (j > 9) {
            this->sudokuBoard[randomY][randomX] = 0;
            continue;
        };

        // Increase the count of filled cells
        i++;
    } while (i != maxFilledSquares);
    // Copy the generated Sudoku board to originalBoard
    this->originalBoard = sudokuBoard;
}