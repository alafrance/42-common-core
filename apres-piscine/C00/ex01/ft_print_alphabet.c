#include <unistd.h>
void ft_print_alphabet(void)
{
    int i = 97;
    while (i != 123)
    {
        write(1, &i, 1 );
        i++;
    }
}
