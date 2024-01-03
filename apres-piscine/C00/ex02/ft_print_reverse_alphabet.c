#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
    int i = 122;
    while (i != 96)
    {
        write(1, &i, 1 );
        i--;
    }
}