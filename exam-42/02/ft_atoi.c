#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str){
    int nb = 0;
    int i = 0;
    int sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)){
        i++;
    }
    if (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-'){
            sign = -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9'){
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return nb * sign;
}


int main()
{
    printf("ft_atoi : %d\n", ft_atoi("    \n\n\v\f\r\t -5234AAAgreghrsth"));
    printf("atoi : %d\n", atoi("    \n\n\v\f\r\t -5234AAAgreghrsth"));
    return 0;
}
