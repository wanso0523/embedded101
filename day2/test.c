#include <stdio.h>
#include <assert.h>
#include "my_strlen.h"

int main(void)
{
    assert(my_strlen("") == 0);
    assert(my_strlen("a") == 1);
    assert(my_strlen("hello") == 5);
    assert(my_strlen("\0") == 0);
    assert(my_strlen("嵌入式Linux") == 14); // UTF-8 字节长度
    printf("All tests passed!\n");
    return 0;
}