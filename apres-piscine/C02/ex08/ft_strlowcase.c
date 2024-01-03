char *ft_strlowcase(char *str)
{
    int i = 0;
    while (str[i++])
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    return (str);
}
/*
#include <stdio.h>
int main(){
    char str[] = "asdf qWeRtY ZXCV";
    printf("%s", ft_strlowcase(str));
}
*/