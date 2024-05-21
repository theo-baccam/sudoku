#include <vector>
#include <raylib.h>
#include "Controller.hpp"
#include "SudokuBoard.hpp"
#include "Window.hpp"
#include <iostream>


// Constructor of the Controller class
Controller::Controller() {
    // Generate a Sudoku board with 40% of the cells filled
    board.generateBoard(0.40);
}
// Destructor of the Controller class
Controller::~Controller() {}

// Method to run the game
void Controller::run() {
    // Initialize a window with dimensions 800x800 and title "Sudoku"
    InitWindow(800, 800, "Sudoku");

    // Loop until the window should close
    while(!WindowShouldClose()) {
        // Check if a number key is pressed
        int pressedNumber = window.getPressedNumber();
        if (pressedNumber != -1) {
             // Get the coordinates of the hovered square
            const int y = window.getHoveredSquareY();
            const int x = window.getHoveredSquareX();

            // If the original Sudoku board at the hovered square is empty
            if (board.originalBoard[y][x] == 0) {
                 // Set the value of the Sudoku board at the hovered square to the pressed number
                board.sudokuBoard[y][x] = pressedNumber;
            }
        };
        // Draw the Sudoku board
        window.drawSudokuBoard(board.sudokuBoard, board.originalBoard);
    };

    CloseWindow();
}