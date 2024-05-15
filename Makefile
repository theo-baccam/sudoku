CC = g++
ESSENTIAL_FLAGS = -I include/ -L lib/
RAYLIB_FLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

EXECUTABLE = sudoku
TEST_SUDOKU_BOARD_INIT_EXE = test-sudoku-board-init.exe


all: $(wildcard src/*.cpp)
	$(CC) $^ $(ESSENTIAL_FLAGS) $(RAYLIB_FLAGS) -o $(EXECUTABLE)

test-sudoku-board-init: src/sudokuBoard.cpp tests/sudokuBoardInitialization.cpp
	$(CC) $(^) $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_INIT_EXE)

clean:
	rm -f $(EXECUTABLE)