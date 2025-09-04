CC = gcc
CFLAGS = -Wall -Wextra
INCLUDE_FLAG = -Iinclude
NAME = UltraCarSimulator4000X
EXECUTABLE = -o $(NAME)
SRC_FILES = $(wildcard src/*.c)

.DEFAULT_GOAL := dev_run

run:
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) $(EXECUTABLE) $(SRC_FILES)
	./$(NAME)
	rm $(NAME)

dev_run:
	$(CC) $(INCLUDE_FLAG) $(EXECUTABLE) $(SRC_FILES)
	./$(NAME)
	rm $(NAME)

debug:
	$(CC) $(INCLUDE_FLAG) $(EXECUTABLE) $(SRC_FILES) -g
	gdb ./$(NAME)