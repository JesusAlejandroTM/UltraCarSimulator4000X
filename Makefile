CC = gcc
NAME = UltraCarSimulator4000X
SRC_FILES = $(wildcard src/*.c)
BINARY_PATH = ./bin/$(NAME)

CFLAGS = -Wall -Wextra
INCLUDE_FLAG = -Iinclude
BINARY_PATH_FLAG = -o $(BINARY_PATH)

.DEFAULT_GOAL := dev_run

run:
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) $(BINARY_PATH_FLAG) $(SRC_FILES)
	$(BINARY_PATH)
	rm $(BINARY_PATH)
	clear

dev_run:
	$(CC) $(INCLUDE_FLAG) $(BINARY_PATH_FLAG) $(SRC_FILES)
	$(BINARY_PATH)
	rm $(BINARY_PATH)
	clear

debug:
	$(CC) $(INCLUDE_FLAG) $(BINARY_PATH_FLAG) $(SRC_FILES) -g
	gdb ./$(BINARY_PATH)