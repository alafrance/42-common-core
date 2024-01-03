#include <unistd.h>
int     ft_strlen(char *str){
    int i;
    
    i = 0;
    while(str[++i]);
    return i;
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_whitespace(char c){
    if(c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}
int check_base(char *base){
    int i;
    int j;
    char c;

    j = 0;
    i = 0;
    if(ft_strlen(base) == 0 || ft_strlen(base) == 1)
        return 0;
    while(base[i]){
		if(base[i] == '+' || base[i] == '-' || is_whitespace(base[i]) || base[i] < 32)
            return 0;
        c = base[i];
        j = i + 1;
        while(base[j]){
            if(c == base[j])
                return 0; 
            j++;
        }
        i++;
    }
    return 1;
}


void ft_putnbr_base(int nb, char *base)
{
    long nbr;
    int base_l;

    base_l = ft_strlen(base);
    if (check_base(base)){
        if (nb < 0) {
            ft_putchar('-');
            nb *= -1;
        }
        nbr = nb;
        if (nbr >= base_l){
            nbr = nbr / base_l;
            ft_putnbr_base(nbr, base);
        }
        nb = nb % base_l;
        ft_putchar(base[nb]);
    }
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char const *av[])
{
	if (ac == 3)
    	ft_putnbr_base(atoi(av[1]), (char *)av[2]);   
    return 0;
}
*/
