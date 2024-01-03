#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
int ft_strlen(char *str){
    int i = 0;
    while(str[++i]);
    return i;
}


void search_and_replace(char *src, char s, char r){
    int i = 0;
    while(src[i]){
        if (src[i] == s){
            ft_putchar(r);
        }else{
            ft_putchar(src[i]);
        }
        i++;
    }
}
int main(int ac, char *av[])
{
    if (ac == 4 && ft_strlen(av[2]) == 1 && ft_strlen(av[3]) == 1){
        search_and_replace(av[1], av[2][0], av[3][0]);
    }
    ft_putchar('\n');
    return 0;
}