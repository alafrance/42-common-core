#include <stdlib.h>
int ft_strlen(char *str){
    int i;
    i = 0;
    while (str[++i]);
    return i;
}

char *ft_strdup(char *str){
    int i = 0;
    char *cpy;
    if (!(cpy = malloc((ft_strlen(str) + 1) * sizeof(char)))){
        return NULL;
    }
    while (str[i]){
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0'; 
    return cpy;
}



#include <string.h>
#include <stdio.h>
int main(int ac, char *av[])
{
    if (ac == 2){
        printf("strdup : %s\n", ft_strdup(av[1]));
        printf("ft_strdup : %s\n", strdup(av[1]));
    }
    return 0;
}
