#include <vector>
#include <raylib.h>
#include "Window.hpp"


Window::Window() {}
Window::~Window() {}

int Window::getPressedNumber() {
    const int pressedKey = GetKeyPressed();
    if (48 <= pressedKey && pressedKey <= 57) return pressedKey - 48;
    return -1;
}

int Window::getHoveredSquareY() {
    return GetMouseY() / (GetScreenWidth() / 9);
}

int Window::getHoveredSquareX() {
    return GetMouseX() / (GetScreenWidth() / 9);
}

void Window::drawSudokuBoard(
    std::vector<std::vector<int>> sudokuBoard,
    std::vector<std::vector<int>> originalBoard
) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int cellSize = GetScreenWidth() / 9;
            int x = j * cellSize;
            int y = i * cellSize;

            DrawRectangleLines(x, y, cellSize, cellSize, LIGHTGRAY);

            Color color;
            originalBoard[i][j] != 0 ? color = BLACK : color = DARKBLUE;

            if (sudokuBoard[i][j] != 0) {
                DrawText(
                    TextFormat("%i",
                    sudokuBoard[i][j]),
                    x + cellSize / 2 - 10,
                    y + cellSize / 2 - 20, 40, color
                );
            }
        }
    }

    EndDrawing();
}