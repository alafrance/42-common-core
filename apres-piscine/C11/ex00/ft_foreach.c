#include <unistd.h>
void ft_foreach(int *tab, int length, void(*f)(int)){
	int i;

	i = 0;
	while(i != length)
		f(tab[i++]);
}
/*
#include <stdio.h>
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
}
int main(){
	int tab[5] = {2, 4, 5, 3, 5};
	ft_foreach(tab, 5, &ft_putnbr);
	printf("%d %d %d %d", tab[1], tab[2], tab[3], tab[4]);
}
*/
