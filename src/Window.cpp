#include <vector>
#include <raylib.h>
#include "Window.hpp"

// Constructor of the Window class
Window::Window() {}

// Destructor of the Window class
Window::~Window() {}

// Get the number pressed on the keyboard
int Window::getPressedNumber() {
    const int pressedKey = GetKeyPressed();
    // If the pressed key is a number (ASCII 48-57), return the number
    if (48 <= pressedKey && pressedKey <= 57) return pressedKey - 48;
    // If the pressed key is not a number, return -1
    return -1;
}

// Get the y-coordinate of the square hovered by the mouse
int Window::getHoveredSquareY() {
    // The screen is divided into 9 squares vertically
    return GetMouseY() / (GetScreenWidth() / 9);
}

// Get the x-coordinate of the square hovered by the mouse
int Window::getHoveredSquareX() {
    // The screen is divided into 9 squares horizontally
    return GetMouseX() / (GetScreenWidth() / 9);
}

// Draw the Sudoku board
void Window::drawSudokuBoard(
    std::vector<std::vector<int>> sudokuBoard,
    std::vector<std::vector<int>> originalBoard
) {
    // Begin drawing
    BeginDrawing();

    // Clear the background
    ClearBackground(RAYWHITE);

    // Draw the Sudoku board
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            // Calculate the size and position of the cell
            int cellSize = GetScreenWidth() / 9;
            int x = j * cellSize;
            int y = i * cellSize;

            // Draw the cell
            DrawRectangleLines(x, y, cellSize, cellSize, LIGHTGRAY);

            // Choose the color of the number
            Color color;
            // If the number is from the original board, color it black
            originalBoard[i][j] != 0 ? color = BLACK : color = DARKBLUE;

            // If the cell is not empty, draw the number
            if (sudokuBoard[i][j] != 0) {
                DrawText(
                    TextFormat("%i", sudokuBoard[i][j]),
                    x + cellSize / 2 - 10,
                    y + cellSize / 2 - 20, 40, color
                );
            }
        }
    }

    // End drawing
    EndDrawing();
}