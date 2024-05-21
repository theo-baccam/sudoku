#pragma once
#include <vector>


class Window {
    public:
        Window();
        ~Window();

        void drawSudokuBoard(std::vector<std::vector<int>> sudokuBoard);
};