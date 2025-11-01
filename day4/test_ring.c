#include <stdio.h>
#include <assert.h>
#include "ringbuf.h"
int main(void)
{
    ringbuf_t rb = {0};
    int v;
    /* 基本 push/pop */
    assert(ring_push(&rb, 1));
    assert(ring_push(&rb, 2));
    assert(ring_pop(&rb, &v) && v == 1);
    assert(ring_pop(&rb, &v) && v == 2);
    /* 满/空边界 */
    for (int i = 0; i < RING_SIZE; i++) assert(ring_push(&rb, i));
    assert(!ring_push(&rb, 999));          // 满
    for (int i = 0; i < RING_SIZE; i++) assert(ring_pop(&rb, &v) && v == i);
    assert(!ring_pop(&rb, &v));            // 空
    printf("All tests passed!\n");
    return 0;
}