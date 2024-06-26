CC = g++
ESSENTIAL_FLAGS = -I include/ -L lib/
RAYLIB_FLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

EXECUTABLE = sudoku
TEST_SUDOKU_BOARD_INIT_EXE = test-sudoku-board-init.exe
TEST_SUDOKU_BOARD_IS_VALID_HORIZONTAL_EXE = test-sudoku-board-is-valid-horizontal.exe
TEST_SUDOKU_BOARD_IS_VALID_VERTICAL_EXE = test-sudoku-board-is-valid-vertical.exe
TEST_SUDOKU_BOARD_IS_VALID_BLOCK_EXE = test-sudoku-board-is-valid-block.exe
TEST_SUDOKU_BOARD_IS_BOARD_COMPLETE_EXE = test-sudoku-board-is-complete.exe
TEST_SUDOKU_BOARD_GENERATE_BOARD_EXE = test-sudoku-board-generate-board.exe


all: $(wildcard src/*.cpp)
	$(CC) $^ $(ESSENTIAL_FLAGS) $(RAYLIB_FLAGS) -o $(EXECUTABLE)

test-sudoku-board-init: src/sudokuBoard.cpp tests/sudokuBoardInitialization.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_INIT_EXE)

test-sudoku-board-is-valid-horizontal: src/sudokuBoard.cpp tests/sudokuBoard_isValidHorizontal.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_IS_VALID_HORIZONTAL_EXE)

test-sudoku-board-is-valid-vertical: src/sudokuBoard.cpp tests/sudokuBoard_isValidVertical.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_IS_VALID_VERTICAL_EXE)

test-sudoku-board-is-valid-block: src/sudokuBoard.cpp tests/sudokuBoard_isValidBlock.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_IS_VALID_BLOCK_EXE)

test-sudoku-board-is-board-complete: src/sudokuBoard.cpp tests/sudokuBoard_isBoardComplete.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_IS_BOARD_COMPLETE_EXE)

test-sudoku-board-generate-board: src/sudokuBoard.cpp tests/sudokuBoard_generateBoard.cpp
	$(CC) $^ $(ESSENTIAL_FLAGS) -o $(TEST_SUDOKU_BOARD_GENERATE_BOARD_EXE)

clean:
	rm -f $(EXECUTABLE)
	rm -f $(TEST_SUDOKU_BOARD_INIT_EXE)
	rm -f $(TEST_SUDOKU_BOARD_IS_VALID_HORIZONTAL_EXE)
	rm -f $(TEST_SUDOKU_BOARD_IS_VALID_VERTICAL_EXE)
	rm -f $(TEST_SUDOKU_BOARD_IS_VALID_BLOCK_EXE)