#include "my_strlen.h"

size_t my_strlen(const char *s)
{
    const char *p = s;
    while (*p != '\0')
        ++p;
    return (size_t)(p - s);
}