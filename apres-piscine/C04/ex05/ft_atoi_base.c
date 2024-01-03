int is_whitespace(char c){
    if(c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}
int     ft_strlen(char *str){
    int i;
    
    i = 0;
    while(str[++i]);
    return i;
}
int check_base(char *base){
    int i;
    int j;
    char c;

    j = 0;
    i = 0;
    if(ft_strlen(base) == 0 || ft_strlen(base) == 1)
        return 0;
    while(base[i]){
		if(base[i] == '+' || base[i] == '-' || is_whitespace(base[i]) || base[i] < 32)
            return 0;
        c = base[i];
        j = i + 1;
        while(base[j]){
            if(c == base[j])
                return 0; 
            j++;
        }
        i++;
    }
    return 1;
}

int is_present(char c, char *base){
    int i;
    i = 0;
    while(base[i]){
        if(c == base[i])
            return 1;
        i++;
    }
    return 0;
}
int ft_get_index_base(char c, char *base){
	int i;

	i = 0;
	while(base[i]){
		if (base[i] == c)
			return i;
		i++;
	}
	return i;
}


int ft_atoi_base(char *str, char *base){
    int i = 0;
    int sign = 1;
    int atoi = 0;
    int base_l;

    if(!check_base(base))
        return 0;
    base_l = ft_strlen(base);
    while(is_whitespace(str[i])){
		i++;
	}
    while(str[i] == '-' || str[i] == '+'){
        if(str[i++] == '-')
            sign *= -1;
    }
    while (is_present(str[i], base)){
		atoi = (atoi * base_l) + ft_get_index_base(str[i], base);
        i++;
    }
    return atoi * sign;
}

/*
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char *av[])
{
    printf("%d", ft_atoi_base(av[1], av[2]));
    return 0;
}
*/
