#pragma once
#include <vector>


class Window {
    public:
        SudokuBoard();
        ~SudokuBoard();

        void drawSudokuBoard(std::vector<std::vector<int>> sudokuBoard);
};