#include <vector>
#include <raylib.h>
#include "Controller.hpp"
#include "SudokuBoard.hpp"
#include "Window.hpp"
#include <iostream>


Controller::Controller() {
    board.generateBoard(0.40);
}
Controller::~Controller() {}

void Controller::run() {
    InitWindow(800, 800, "Sudoku");

    while(!WindowShouldClose()) {
        int pressedNumber = window.getPressedNumber();
        if (pressedNumber != -1) std::cout << pressedNumber << '\n';
        window.drawSudokuBoard(board.sudokuBoard, board.originalBoard);
    };

    CloseWindow();
}