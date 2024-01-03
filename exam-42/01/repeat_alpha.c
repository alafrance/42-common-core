#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    while(*str){
        ft_putchar(*str++);
    }
}

void repeat_alpha(char *str){
    int i = 0;
    int j = 0;
    while(str[i]){
        if (str[i] >= 'a' && str[i] <= 'z'){
            while(j != str[i] - 'a' + 1){
                ft_putchar(str[i]);
                j++;
            }
            j = 0;
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            while(j != str[i] - 'A'+ 1){
                ft_putchar(str[i]);
                j++;
            }
            j = 0;
        }else{
            ft_putchar(str[i]);
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2){
        repeat_alpha(argv[1]);
    }
    ft_putchar('\n');
    return 0;
}
