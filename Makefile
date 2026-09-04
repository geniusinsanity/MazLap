CC = gcc

CFLAGS = -Wall -Wextra -std=c17 $(shell pkg-config --cflags raylib)

LDFLAGS = $(shell pkg-config --libs raylib)

TARGET = main

SRC = src/main.c src/maze/maze.c

.PHONY: all run clean

all: run

run: $(TARGET)
	./$(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)