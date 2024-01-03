#include <unistd.h>


int ft_strlen(char *str){
    int i = 0;
    while (str[++i]);
    return i;
}

void ft_putchar(char c){
    write(1, &c, 1);
}

int is_white_space(char c){
    if (c == ' ' || (c >= 9 && c <= 13)){
        return 1;
    }
    return 0;
}

void last_word(char *str){
    int i = ft_strlen(str) - 1;
    while (is_white_space(str[i])){
        i--;
    }
    while (!is_white_space(str[i]) && i != 0){
        i--;
    }
    if (is_white_space(str[i])){
        i++;
    }
    while(!is_white_space(str[i]) && str[i]){
        ft_putchar(str[i]);
        i++;
    }
}


int main(int ac, char *av[])
{
    if (ac == 2){
        last_word(av[1]);
    }
    ft_putchar('\n');
    return 0;
}