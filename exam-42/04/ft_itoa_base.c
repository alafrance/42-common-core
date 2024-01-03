#include <stdlib.h>

int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[++i]);
    return i;
}

char *ft_strrev(char *str){
    int i;
    int j;
    char tmp;
    j = ft_strlen(str) - 1;
    i = 1;
    while(j > i){
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}

char	*ft_itoa_base(int value, int base){
    char *itoa;
    int i;

    i = 0;
    if(value == 0)
        return "0";
    itoa = malloc(sizeof(char) * 12);
    if(value < 0){
        value *= -1;
        itoa[i++] = '-';
    }
    while(value != 0){
        if(value % base >= 10)
            itoa[i] = value % base + 'A' - 10;
        else
            itoa[i] = value % base + '0';
        value /= base;
        i++;
    }
    itoa[i] = '\0';
    return ft_strrev(itoa);
}