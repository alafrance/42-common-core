int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int is_lowercase(char c){
    return (c >= 'a' && c <= 'z') ? 1 : 0;
}
int is_number(char c){
    return (c >= '1' && c <= '9') ? 1 : 0;
}
int is_word(char c){
    return (is_lowercase(c) || is_uppercase(c) || is_number(c)) ? 1 : 0;
}

char *ft_strcapitalize(char *str)
{
    int i = 0;
    if (is_lowercase(str[i]))
        str[i] = str[i] - 32;
    i++;
    while (str[i]){
        if (!is_word(str[i]) && is_lowercase(str[i + 1])){
            i++;
            str[i] -= 32;
        }
        i++;
        while (is_word(str[i])){
            if(is_uppercase(str[i]))
                str[i] += 32;
            i++;
        }
    }
    return str;
}

/*
#include <stdio.h>
int main()
{
    char str[] = "salut,comment tu vas ? 42moTs quarante-deux; cinquante+et+un1";
    printf("%s", ft_strcapitalize(str));
}
*/