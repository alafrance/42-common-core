#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int nb);

int size(int a)
{
    int i = 10;
    int count = 1;
    while (i <= a)
    {
        i *= 10;
        count++;
    }
    return count;
}

void print_less_zero(int a, int n)
{
    int i = 0;
    while (i != n - size(a) )
        {
            ft_putnbr(0);
            i++;
        }
}

void ft_print_combn(int n)
{
    if (n > 0 && n < 10)
    {
        int a = 0;
  //      while (size(a) != n)
    //    {
            print_less_zero(a,n);
            ft_putnbr(a);
     //   }
    } 
}

void ft_putnbr(int nb)
{
    long nbr;
    if (nb < 0)
    {
        write(1, "-", 1);
        nb *= -1;
    }
    nbr = nb;
    if (nbr >= 10)
    {
        nbr = nbr / 10;
        ft_putnbr(nbr);
    }
    nb = nb % 10 + 48;
    write(1, &nb, 1);

}

int main(int ac, char **av)
{
    ft_print_combn(3);
 //   printf("%d", size(100));
    return 0;
}