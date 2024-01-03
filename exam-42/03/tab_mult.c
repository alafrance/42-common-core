#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    int i;

    i = 0;
    while(str[i])
        ft_putchar(str[i++]);
}
int is_whitespace(char c ){
    return (c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0;
}

void ft_putnbr(int nb){
    long nbr;
    if(nb < 0){
        ft_putchar('-');
        nb *= -1;
    }
    nbr = nb;
    if(nbr >= 10){
        nbr /= 10;
        ft_putnbr(nbr);
    }
    nb = nb % 10 + 48;
    ft_putchar(nb);
}
int ft_atoi(char *str){
    int i;
    int nb;
    int sign;

    sign = 1;
    i = 0;
    nb = 0;
    while(is_whitespace(str[i]))
        i++;
    while(str[i] == '-' || str[i] == '+'){
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        nb = nb * 10 + str[i] - 48;
        i++;
    }
    return nb * sign;

}
void ft_mult(int nb){
    int i;

    i = 1;
    while(i != 10){
        ft_putnbr(i);
        ft_putstr(" * ");
        ft_putnbr(nb);
        ft_putstr(" = ");
        ft_putnbr(i * nb);
        if(i != 9)
            ft_putchar('\n');
        i++;
    }
}

int main(int ac, char **av){
    if(ac == 2)
        ft_mult(ft_atoi(av[1]));
    ft_putchar('\n');
}