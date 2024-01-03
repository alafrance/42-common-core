#include <stdlib.h>
#include <limits.h>
int ft_size(int nb){
    int count;

    count = 0;
    if(nb < 0)
        nb *= -1;
    if(nb == 0)
        return 1;
    while(nb > 0){
        count++;
        nb /= 10;
    }
    return count;
}

int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[++i]);
    return i;
}

char *ft_strrev(char *str){

    int i;
    int end;
    char tmp;
    end = ft_strlen(str);
    i = 0;
    while(end > i){
        end--;
        tmp = str[i];
        str[i] = str[end];
        str[end] = tmp;
        i++;
    }
    return str;
}

char	*ft_itoa(int nbr){
    char *itoa;
    int i;

    i = 0;
    if(nbr == 0)
        return "0";
    if(nbr < 0 ){
        itoa = malloc(sizeof(char) * (ft_size(nbr) + 1));
        itoa[ft_size(nbr)] = '-';
        nbr *= -1;
    }else
        itoa = malloc(sizeof(char) * ft_size(nbr));

    while(nbr != 0){
        itoa[i] = nbr % 10 + '0';
        i++;
        nbr /= 10;
    }
    return ft_strrev(itoa);
}