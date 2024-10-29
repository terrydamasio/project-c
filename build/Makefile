CC = gcc
CFLAGS = -Iinclude

SRC = src/main.c src/game.c src/snake.c
OBJ = $(SRC:.c=.o)
TARGET = build/snake_game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
