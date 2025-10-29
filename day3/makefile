CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = swap.c test_swap.c
TARGET = test_swap

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

gdb: $(TARGET)
	gdb -tui ./$(TARGET)

.PHONY: clean gdb