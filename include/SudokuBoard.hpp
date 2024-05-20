#pragma once
#include <vector>


class SudokuBoard {
    public:
        std::vector<std::vector<int>> sudokuBoard;
        std::vector<std::vector<int>> originalBoard;

        SudokuBoard();
        ~SudokuBoard();

        void generateBoard();
        void pokeBoard(int numberOfHoles);
        bool isValidHorizontal(int y, int x);
        bool isValidVertical(int y, int x);
        bool isValidBlock(int y, int x);
        bool isBoardComplete();
        void generateBoard(double densityFraction);
};