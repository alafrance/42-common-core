#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}

void rotone(char *str){
    int i = 0;
    while(str[i]){
        if ((str[i] >= 'a' && str[i] < 'z') || (str[i] >= 'A' && str[i] < 'Z')){
            ft_putchar(str[i] + 1);
        }else if(str[i] == 'z'){
            ft_putchar('a');
        }else if(str[i] == 'Z'){
            ft_putchar('A');
        }else{
            ft_putchar(str[i]);
        }
        i++;
    }
}


int main(int ac, char *av[])
{
    if(ac == 2){
        rotone(av[1]);
    }
    ft_putchar('\n');
    return 0;
}