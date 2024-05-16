CC = g++
ESSENTIAL_FLAGS = -I include/ -L lib/
RAYLIB_FLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

EXECUTABLE = sudoku
TEST_SUDOKU_BOARD_INIT_EXE = test-sudoku-board-init.exe
TEST_SUDOKU_BOARD_IS_VALID_HORIZONTAL_EXE = test-sudoku-board-is-valid-horizontal.exe
TEST_SUDOKU_BOARD_IS_VALID_VERTICAL_EXE = test-sudoku-board-is-valid-vertical.exe


all: $(wildcard src/*.cpp)
	$(CC) $^ $(ESSENTIAL_FLAGS) $(RAYLIB_FLAGS) -o $(EXECUTABLE)

test-sudoku-board-init: src/sudokuBoard.cpp tests/sudokuBoardInitialization.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_INIT_EXE)

test-sudoku-board-is-valid-horizontal: src/sudokuBoard.cpp tests/sudokuBoard_isValidHorizontal.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_IS_VALID_HORIZONTAL_EXE)

test-sudoku-board-is-valid-vertical: src/sudokuBoard.cpp tests/sudokuBoard_isValidVertical.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_IS_VALID_VERTICAL_EXE)

clean:
	rm -f $(EXECUTABLE)
	rm -f $(TEST_SUDOKU_BOARD_INIT_EXE)
	rm -f $(TEST_SUDOKU_BOARD_IS_VALID_HORIZONTAL_EXE)
	rm -f $(TEST_SUDOKU_BOARD_IS_VALID_VERTICAL_EXE)