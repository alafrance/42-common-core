#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}

int is_whitespace(char c){
    return (c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0;
}



int ft_atoi(char *str){
    int nb;
    int sign;
    int i;

    i = 0;
    sign = 1;
    while(is_whitespace(str[++i]));
    while(str[i] == '-' || str[i] == '+'){
        if(str[i++] == '-')
            sign *= -1;
    }
    while(str[i] >= '0' && str[i] <= '9')
        nb = (nb * 10) + (str[i++] - 48);
    return nb * sign;
}



#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int nb;
    nb = ft_atoi("      \t \r     -----+++--1045p234ab567");
    nb = ft_atoi((char*)argv[1]);
	//ft_putnbr(nb);
    printf("%d", nb);
    return 0;
}

