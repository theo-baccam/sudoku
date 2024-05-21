#include <vector>
#include <raylib.h>
#include "Controller.hpp"
#include "SudokuBoard.hpp"
#include "Window.hpp"
#include <iostream>


Controller::Controller() {
    board.sudokuBoard = {
        {0, 3, 4,   6, 7, 0,   9, 1, 2},
        {6, 7, 2,   1, 9, 5,   3, 4, 8},
        {1, 9, 8,   3, 4, 2,   5, 6, 7},

        {8, 5, 9,   7, 6, 1,   4, 2, 3},
        {4, 2, 6,   8, 5, 3,   7, 9, 1},
        {7, 1, 3,   0, 2, 4,   8, 5, 6},

        {9, 6, 1,   5, 3, 7,   2, 8, 0},
        {2, 8, 7,   4, 1, 9,   6, 3, 5},
        {3, 4, 5,   2, 0, 6,   1, 7, 9}
    };
    board.originalBoard = board.sudokuBoard;
}
Controller::~Controller() {}

void Controller::run() {
    InitWindow(800, 800, "Sudoku");

    while(!WindowShouldClose()) {
        int pressedNumber = window.getPressedNumber();
        if (pressedNumber != -1 && !board.isBoardComplete()) {
            const int y = window.getHoveredSquareY();
            const int x = window.getHoveredSquareX();

            if (board.originalBoard[y][x] == 0) {
                board.sudokuBoard[y][x] = pressedNumber;
            }
        };
        BeginDrawing();

        ClearBackground(RAYWHITE);

        window.drawSudokuBoard(board.sudokuBoard, board.originalBoard);

        if (board.isBoardComplete()) {
            window.drawWinText();
        };
        EndDrawing();
    };

    CloseWindow();
}