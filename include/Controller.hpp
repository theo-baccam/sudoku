#pragma once
#include "SudokuBoard.hpp"
#include "Window.hpp"


class Controller {
    public:
        SudokuBoard board;
        Window window;

        Controller();
        ~Controller();

        void run();
};