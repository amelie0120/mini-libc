#include <unistd.h>

void puts(const char *str)
{
    while ((*str) != '\0')
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
