CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = ringbuf.c test_ring.c
TARGET = test_ring

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

check: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

helgrind: $(TARGET)
	valgrind --tool=helgrind ./$(TARGET)

.PHONY: clean check helgrind