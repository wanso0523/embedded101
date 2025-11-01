#ifndef RINGBUF_H
#define RINGBUF_H
#include <stddef.h>
#include <stdbool.h>
#define RING_SIZE 16
typedef struct {
    int buf[RING_SIZE];
    size_t head;
    size_t tail;
    size_t count;
} ringbuf_t;
bool ring_push(ringbuf_t *rb, int val);
bool ring_pop(ringbuf_t *rb, int *out);
size_t ring_count(const ringbuf_t *rb);
#endif