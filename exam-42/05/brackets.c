#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    int i;

    i = 0;
    while(str[i])
        ft_putchar(str[i++]);
}
int is_bracket_open(char c){
    return (c == '(' || c == '[' || c == '{') ? 1 : 0;
}
int is_bracket_close(char c){
    return (c == ')' || c == ']' || c == '}' ) ? 1 : 0;
}
int match_brackets(char a, char b){
    return (a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']');
}
int brackets(char *str){
    int i;
    int j;
    int stack[4096];

    i = 0;
    j = 0;
    while(str[i]){
        if(is_bracket_open(str[i]))
            stack[++j] = str[i];
        else if(is_bracket_close(str[i]))
            if(!match_brackets(stack[j--], str[i]))
                return 0;
        i++;
    }
    return 1;
}

int main(int ac, char **av){
    int i;

    i = 1;
    if(ac == 1)
        ft_putchar('\n');
    if(ac >= 2){
        while(i != ac){
            if(brackets(av[i]))
                ft_putstr("OK\n");
            else
                ft_putstr("Error\n");
            i++;
        }
    }
}