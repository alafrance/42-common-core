#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[++i]);
    return i;
}

void display_word(char *str, int begin, int end){
    while(begin != end + 1){
        ft_putchar(str[begin]);
        begin++;
    }
}
void rev_wstr(char *str){
    int i;
    int remember;
    int first_word;

    first_word = 0; 
    i = ft_strlen(str) - 1;
    remember = 0;
    while(i != 0 && (str[i] == ' ' || str[i] == '\t'))
        i--;
    while(i != 0){
        remember = i;
        while(i != 0 && str[i] != ' ' && str[i] != '\t')
            i--;
        if(first_word != 0)
                ft_putchar(' ');
        first_word = 1;
        if(i == 0)
            display_word(str, i, remember);
        else
            display_word(str, i + 1, remember);
        while(i != 0 && (str[i] == ' ' || str[i] == '\t'))
            i--;
    }
}

int main(int ac, char **av){
    if(ac == 2)
        rev_wstr(av[1]);
    ft_putchar('\n');
}
