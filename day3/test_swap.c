#include <stdio.h>
#include <assert.h>
#include "swap.h"

int main(void)
{
    int x = 10, y = 20;

    /* 值传递测试 */
    swap_int(x, y);
    assert(x == 10 && y == 20);        // 外部没变化

    /* 地址传递测试 */
    swap_ptr(&x, &y);
    assert(x == 20 && y == 10);        // 外部已交换

    printf("All tests passed!\n");
    return 0;
}