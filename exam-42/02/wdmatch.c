#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i++]);
    return (i);
}

void ft_putchar(char c){
    write(1, &c, 1);
}

void ft_putstr(char *str){
    int i = 0;
    while (str[i]){
        ft_putchar(str[i]);
        i++;
    }
}

void wdmatch(char *s1, char *s2){
    int i = 0, j = 0, len = ft_strlen(s1) - 1;
    while (s2[j] && i < len){
        if (s1[i] == s2[j]){
            i++;
        }
        j++;
    }
    if (i == len){
        ft_putstr(s1);
    }
}
int main(int ac, char *av[])
{
    if (ac == 3){
        wdmatch(av[1], av[2]);
    }
    ft_putchar('\n');
    return 0;
}