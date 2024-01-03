#include <unistd.h>
int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[++i]);
    return i;
}
void ft_putchar(char c){
    write(1, &c, 1);
}
int go_to_matching(char *src_code, int j){
    int balance;

    balance = 0;
    if(src_code[j] == '['){
        j++;
        while(!(src_code[j] == ']' && balance == 0)){
            if(src_code[j] == '[')
                balance++;
            else if(src_code[j] == ']')
                balance--;
            j++;
        }
        j--;
    }else if(src_code[j] == ']'){
        j--;
        while(!(src_code[j] == '[' && balance == 0)){
            if(src_code[j] == ']')
                balance++;
            else if(src_code[j] == '[')
                balance--;
            j--;
        }
        j--;
    }
    return j;
}
void brainfuck(char *src_code){
    char bytes[2048];
    int i;
    int j;

    j = 0;
    i = -1;
    while(i++ != 2048)
        bytes[i] = 0;
    i = 0;
    while(src_code[j]){
        if(src_code[j] == '>')
            i++;
        else if(src_code[j] == '<')
            i--;
        else if(src_code[j] == '+')
            bytes[i]++;
        else if(src_code[j] == '-')
            bytes[i]--;
        else if(src_code[j] == '.')
            ft_putchar(bytes[i]);
        else if(src_code[j] == '['){
            if(bytes[i] ==  0)
                j = go_to_matching(src_code, j);
        }else if(src_code[j] == ']'){
            if(bytes[i] != 0)
                j = go_to_matching(src_code, j);
        }
        j++;
    }
}

int main(int ac, char **av){
    if(ac == 2)
        brainfuck(av[1]);
    else
        ft_putchar('\n');
}