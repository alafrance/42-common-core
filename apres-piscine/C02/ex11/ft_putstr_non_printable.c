#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_char_is_printable(char c)
{
    return ((c >= ' ' && c <= '~')) ? 1 : 0;
}

void ft_print_nbr_in_base(int nb, int base)
{
    long nbr;
    if (nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }
    nbr = nb;
    if (nbr >= base)
    {
        nbr = nbr / base;
        ft_print_nbr_in_base(nbr, base);
    }
    nb = nb % base + 48;
    if (nb > '9')
        ft_putchar('a' + nb - '9' - 1);
    else
        ft_putchar(nb);
}

void ft_putstr_non_printable(char *str)
{
    int i = 0;
    int val_ascii = 0;
    while (str[i])
    {
        if (ft_char_is_printable(str[i]))
            ft_putchar(str[i]);
        else{
            ft_putchar('\\');
            val_ascii = str[i];
            if (val_ascii <= 15)
                ft_putchar('0');
            ft_print_nbr_in_base(val_ascii, 16);
        }
        i++;  
    }
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    ft_putstr_non_printable("Coucou\r \t \n \v tu vas bien");
    return 0;
}
*/
