#include "swap.h"
#include <stdio.h>

/* 值传递：函数内交换无效 */
void swap_int(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    printf("[swap_int]  a=%d, b=%d\n", a, b);
}

/* 地址传递：函数内交换有效 */
void swap_ptr(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("[swap_ptr] *a=%d, *b=%d\n", *a, *b);
}