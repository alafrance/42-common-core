#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
int is_whitespace(char c){
    return (c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0;
}
int is_uppercase(char c){
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}
int is_lowercase(char c){
    return (c >= 'a' && c <= 'z') ? 1 : 0;
}

void str_capitalizer(char **av, int size){
    int i;
    int j;

    i = 0;
    j = 0;
    while(j != size){
        while(av[j][i]){
            while(is_whitespace(av[j][i]) && av[j][i])
                ft_putchar(av[j][i++]);
            if(av[j][i] != '\0' && is_lowercase(av[j][i])){
                ft_putchar(av[j][i] - 32);
                i++;
            }else if(av[j][i] != '\0'){
                ft_putchar(av[j][i]);
                i++;
            }
            while(!is_whitespace(av[j][i]) && av[j][i]){
                if(is_uppercase(av[j][i]))
                    ft_putchar(av[j][i] + 32);
                else
                    ft_putchar(av[j][i]);
                i++;
            }
        }
        i = 0;
        ft_putchar('\n');
        j++;
    }
}
int main(int ac, char **av){
    if(ac > 1)
        str_capitalizer(av + 1, ac - 1);
    else
        ft_putchar('\n');
}