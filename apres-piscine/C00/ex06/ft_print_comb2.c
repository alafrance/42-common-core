#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putchar_4(char a, char b, char c, char d)
{
        ft_putchar(a);
        ft_putchar(b);
        write(1, " ", 1);
        ft_putchar(c);
        ft_putchar(d);
        if (a != '9' ||  b != '8' || c != '9' || d != '9' )
            write(1, ", ", 2);
}

void ft_print_comb2()
{
    char a = '0';
    char b = '0';
    char c = '0';
    char d = '1';
    while (a <= '9')
    {
        while (b <= '8')
        {
            while (c <= '9')
            {
                while (d <= '9')
                {
                    if (a == c && b < d)
                        ft_putchar_4(a, b, c, d);
                    else if (a < c)
                        ft_putchar_4(a, b, c, d);
                    d++;
                }
                d = '0';
                c++;
            }
            c = '0';
            b++;
        }
        b = '0';
        a++;
    }
}