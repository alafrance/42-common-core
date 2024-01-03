#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    while(*str){
        ft_putchar(*str++);
    }
}


void rev_print(char *str){
    int i = 0;
    while(str[++i]);
    while (i != -1){
        ft_putchar(str[i]);
        i--;
    }
}
int main(int ac, char *av[])
{
    if (ac == 2){
        rev_print(av[1]);
    }
    return 0;
}
