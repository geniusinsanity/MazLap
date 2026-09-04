CC = gcc

CFLAGS = -Wall -Wextra -std=c17

TARGET = main

SRC = src/main.c

.PHONY: all run clean

all: run

run: $(TARGET)
	./$(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)