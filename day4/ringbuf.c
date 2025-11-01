#include "ringbuf.h"
bool ring_push(ringbuf_t *rb, int val)
{
    if (rb->count == RING_SIZE) return false;
    rb->buf[rb->head] = val;
    rb->head = (rb->head + 1) % RING_SIZE;
    rb->count++;
    return true;
}
bool ring_pop(ringbuf_t *rb, int *out)
{
    if (rb->count == 0) return false;
    *out = rb->buf[rb->tail];
    rb->tail = (rb->tail + 1) % RING_SIZE;
    rb->count--;
    return true;
}