

int ft_strcmp(char *s1, char *s2){
    int i = 0;
    while (s1[i]){
        if(s1[i] > s2[i]){
            return s1[i] - s2[i];
        }else if (s1[i] < s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}

/*
#include <string.h>
#include <stdio.h>
int main(int ac, char *av[])
{
    printf("strcmp : %d\n", ft_strcmp(av[1], av[2]));
    printf("ft_strcmp : %d\n", strcmp(av[1], av[2]));
    return 0;
}
*/