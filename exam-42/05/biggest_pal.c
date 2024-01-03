#include <unistd.h>
int is_palindrome(char *str, int i, int end){
    int count;

    count = 0;
    if((end - i == 1 && str[i] == str[end]) || ( end - i == 0))
        return 1;
    while(count != (end - i) / 2 + 1){
        if(str[i + count] != str[end - count])
            return 0;
        count++;
    }
    return 1;
}
void ft_putchar(char c){
    write(1, &c, 1);
}
int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[++i]);
    return i;
}
void print_word(char *str, int begin, int end){
    if(begin > end)
        return ;
    while(begin != end + 1)
        ft_putchar(str[begin++]);
}
void biggest_pal(char *str){
    int i;
    int remember;
    int end;
    int r_i;
    int r_end;

    remember = 0;
    i = 0;
    end = ft_strlen(str) - 1;
    r_i = 0;
    r_end = 0;
    while(end != 0){
        if(r_end - r_i <= end - i && is_palindrome(str, i, end)){
            r_i = i;
            r_end = end;
        }
        if(i == end){
            end--;
            i = 0;
        }else
            i++;
    }
    print_word(str, r_i, r_end);
}

int main(int ac, char **av){
    if(ac == 2)
        biggest_pal(av[1]);
    ft_putchar('\n');
}