#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}
int is_whitespace(char c){
    return (c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0;
}

void epur_str(char *str){
    int i;

    i = 0;
    while(str[i]){
        while(is_whitespace(str[i]) && str[i])
            i++;
        while(!is_whitespace(str[i]) && str[i]){
            ft_putchar(str[i]);
            i++;
        }
        if(str[i] != '\0')
            ft_putchar(' ');
        
    }

}
int main(int ac, char **av){
    if (ac == 2)
        epur_str(av[1]);
    ft_putchar('\n');
    return 0;
}