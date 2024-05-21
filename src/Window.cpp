#include <vector>
#include <raylib.h>
#include "Window.hpp"


Window::Window() {}
Window::~Window() {}

void Window::drawSudokuBoard(std::vector<std::vector<int>> sudokuBoard) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int cellSize = 800 / 9;
            int x = j * cellSize;
            int y = i * cellSize;

            DrawRectangleLines(x, y, cellSize, cellSize, LIGHTGRAY);

            if (sudokuBoard[i][j] != 0) {
                DrawText(
                    TextFormat("%i",
                    sudokuBoard[i][j]),
                    x + cellSize / 2 - 10,
                    y + cellSize / 2 - 20, 40, BLACK
                );
            }
        }
    }

    EndDrawing();
}