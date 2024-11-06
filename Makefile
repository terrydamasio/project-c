CC = gcc
CFLAGS = -Iinclude -L/path/to/cli-lib -lcli
OBJ = src/main.o src/game.o
TARGET = build/snake_game

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

clean:
    rm -f $(OBJ) $(TARGET)
