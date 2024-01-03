#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putnbr(int nb){
    long nbr;
    if(nb < 0){
        ft_putchar('-');
        nb *= -1;
    }
    nbr = nb;
    if (nbr >= 10){
        nbr /= 10;
        ft_putnbr(nbr);
    }
    nb = nb % 10 + 48;
    ft_putchar(nb);
}

int main(int ac, char **av){
    ft_putnbr(ac - 1);
    ft_putchar('\n');
}