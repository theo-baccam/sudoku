#include <vector>
#include <raylib.h>
#include "Controller.hpp"
#include "SudokuBoard.hpp"
#include "Window.hpp"


Controller::Controller() {
    board.generateBoard(0.40);
}
Controller::~Controller() {}

void Controller::run() {
    InitWindow(800, 800, "Sudoku");

    while(!WindowShouldClose()) {
        window.drawSudokuBoard(board.sudokuBoard);
    };

    CloseWindow();
}