char *ft_strupcase(char *str)
{
    int i = 0;
    while (str[i++])
        str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
    return (str);
}

/*
#include <stdio.h>
int main()
{
    char str[] = "asdf qWeRtY ZXCV";
    printf("%s", ft_strupcase(str));
}
*/