#include "../include/raylib.h"

const int boardSize = 9;
int board[boardSize][boardSize] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};


int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Sudoku");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                int cellSize = screenWidth / boardSize;
                int x = j * cellSize;
                int y = i * cellSize;

                DrawRectangleLines(x, y, cellSize, cellSize, LIGHTGRAY);

                if (board[i][j] != 0) {
                    DrawText(TextFormat("%i", board[i][j]), x + cellSize / 2 - 10, y + cellSize / 2 - 20, 40, BLACK);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}