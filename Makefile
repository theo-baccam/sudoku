CC = g++
CFLAGS = -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
EXECUTABLE = sudoku



gui: $(wildcard src/*.cpp)
	$(CC) $^ $(CFLAGS) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)