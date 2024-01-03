#include <unistd.h>
#include "ft_stock_str.h"
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_putchar(char c){
	write(1, &c, 1);
}

void ft_putstr(char *str){
	int i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
}
void ft_putnbr(int nb){
    long nbr;
    if(nb < 0){
        ft_putchar('-');
        nb *= -1;
    }
    nbr = nb;
    if(nbr >= 10){
        nbr = nbr / 10;
        ft_putnbr(nbr);
    }
    nb = nb % 10 + 48;
    ft_putchar(nb);
}
void ft_show_tab(struct s_stock_str *par){
	int i;

	i = 0;
	while(par[i].str != 0){
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}	
}

int main(int ac, char **av){
	struct s_stock_str *ar_stock;
	ar_stock = ft_strs_to_tab(ac, av);
	ft_show_tab(ar_stock);
	return 0;
}
