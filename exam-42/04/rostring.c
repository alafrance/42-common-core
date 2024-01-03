#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void rostring(char *str){
    int i;
    int remember;
    int printed;

    printed = 0;
    remember = 0;
    i = 0;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    if(str[i] == ' ' || str[i] == '\t')
        i++;
    remember = i;
    while(str[i] != ' ' && str[i] != '\t' && str[i])
        i++;
    while(str[i]){
        while((str[i] == ' ' || str[i] == '\t') && str[i])
            i++;
        while(str[i] != ' ' && str[i] != '\t' && str[i]){
            printed = 1;
            ft_putchar(str[i++]);
        }
        if(printed == 1)
            ft_putchar(' '); 
    }
    while(str[remember] != ' ' && str[remember] != '\t' && str[remember])
        ft_putchar(str[remember++]);
}

int main(int ac, char **av){
    if(ac == 2)
        rostring(av[1]);
    ft_putchar('\n');
}
