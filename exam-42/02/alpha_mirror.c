#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}

void alpha_mirror(char *str){
    int i = 0;
    while (str[i]){
        if(str[i] >= 'a' && str[i] <= 'z'){
            ft_putchar('a' + 'z' - str[i]);
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            ft_putchar('A' + 'Z' - str[i]);
        }else{
            ft_putchar(str[i]);
        }
        i++;
    }
}
int main(int ac, char *av[])
{
    if (ac == 2){
        alpha_mirror(av[1]);        
    }
    ft_putchar('\n');
    return 0;
}