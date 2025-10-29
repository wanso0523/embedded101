CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = my_strlen.c test.c
TARGET = test

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

check: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

.PHONY: clean check