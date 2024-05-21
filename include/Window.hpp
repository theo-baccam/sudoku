#pragma once
#include <vector>


class Window {
    public:
        Window();
        ~Window();

        int getPressedNumber();
        int getHoveredSquareY();
        int getHoveredSquareX();
        void drawSudokuBoard(
            std::vector<std::vector<int>> sudokuBoard,
            std::vector<std::vector<int>> originalBoard
        );
        void drawWinText();
};