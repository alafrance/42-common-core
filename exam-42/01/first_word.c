#include <unistd.h>

int is_whitespace(char c){
    if (c == ' ' || c == '\n' || c == '\v' || c == '\t' || c == '\f' || c == '\r'){
        return 1;
    }
    return 0;
}

void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    while(*str){
        ft_putchar(*str++);
    }
}



void first_word(char *str){
    int i = 0;
    while (str[i] && is_whitespace(str[i])){
        i++;
    }
    while (str[i] && !is_whitespace(str[i])){
        ft_putchar(str[i]);
        i++;
    }
}


int main(int ac, char *av[]){
    if (ac == 2){
        first_word(av[1]);
    }
    ft_putchar('\n');
    return 0;
}