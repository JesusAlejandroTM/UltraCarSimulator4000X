CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
NAME = UltraCarSimulator4000X
EXECUTABLE = -o $(NAME)
SRC_FILES = $(wildcard src/*.c)

run:
	$(CC) $(CFLAGS) $(EXECUTABLE) $(SRC_FILES)
	./$(NAME)
	rm $(NAME)