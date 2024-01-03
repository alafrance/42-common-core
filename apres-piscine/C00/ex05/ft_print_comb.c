#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_comb(void)
{
    char i = '0';
    char j = '1';
    char k = '2';

    while (i <= '7')
    {
        while (j <= '8')
        {

            while (k <= '9')
            {
                ft_putchar(i);
                ft_putchar(j);
                ft_putchar(k);
                if (i != '7')
                    write(1, ", ", 2);
                k++;
            }
            j++;
            k = j + 1;
        }
        j = i + 1;
        i++;
    }
}