#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
int is_whitespace(char c){
    return (c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0;
}
int ft_atoi(char *str){
    int i;
    int nb;
    int sign;

    sign = 1;
    nb = 0;
    i = 0;
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
void print_hex(int nb){
    long nbr;
    if(nb < 0){
        ft_putchar('-');
        nb *= -1;
    }
    nbr = nb;
    if(nbr >= 16){
        nbr /= 16;
        print_hex(nbr);
    }
    if(nb % 16 < 10){
        ft_putchar(nb % 16 + '0');
    }
    else{
        ft_putchar(nb % 16 + 'a' - 10);
    }
}
int main(int ac, char **av){
    if(ac == 2)
        print_hex(ft_atoi(av[1]));
    ft_putchar('\n');
}