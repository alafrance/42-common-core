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
    i = 0;
    nb = 0;
    sign = 1;
    while(is_whitespace(str[i]))
        i++;
    while(str[i] == '-' || str[i] == '+'){
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        nb = (nb * 10) + str[i] - '0';
        i++;
    }
    return nb * sign;

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
int is_prime(int nb){
    int i;

    i = 2;
    if(nb < 0 || nb == 0 || nb == 1)
        return 0;
    while(i * i<= nb){
        if(nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}
void ft_add_prime_sum(int nb){
    int sum;
    int i;
    i = 2;
    sum = 0;
    while(i != nb + 1){
        if(is_prime(i))
            sum += i;
        i++;
    }
    ft_putnbr(sum);
}
int main(int ac, char **av)
{
    if(ac == 2)
        ft_add_prime_sum(ft_atoi(av[1]));
    else
       ft_putchar('0');
    ft_putchar('\n');
    return 0;
}
