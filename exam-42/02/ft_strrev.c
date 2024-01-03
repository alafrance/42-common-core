char    *ft_strrev(char *str){
    int begin = 0;
    int end = 0;
    char swap = ' ';
    while (str[end++]);
    end -= 2;
    while (begin <= (end / 2)){
        swap = str[begin];
        str[begin] = str[end];
        str[end] = swap;
        end--;
        begin++;
    }
    return str;

}

#include <stdio.h>

int main(int ac, char *av[])
{
    if (ac == 2){
        printf("%s\n", ft_strrev(av[1]));
    }
    return 0;
}