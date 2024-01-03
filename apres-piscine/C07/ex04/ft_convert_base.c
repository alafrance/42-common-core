#include "ft_convert_base2.c"

char *convert_to_a_base(int nbr, char *base_to){
	int sign;
	char *result;
	int i;
	int size_b;
	sign = 0;
	size_b = ft_strlen(base_to);
	i = 0;
	if (nbr < 0){
		sign = -1;
		i++;
	}
	if (sign == -1){
		if (!(result = malloc(sizeof(char) * (size_malloc_base_10_to_b(nbr, size_b) + 2))))
			return ((void *) 0);
	}else{
		if (!(result = malloc(sizeof(char) * (size_malloc_base_10_to_b(nbr, size_b) + 1))))
			return ((void *) 0);
	}	
	while(nbr != 0){
		result[i] = base_to[nbr % size_b];
		nbr /= size_b;
		i++;
	}
	if(sign == -1)
		result[i++] = '-';
	result[i] = '\0';
	return ft_reverse_char(result);
}

char 	*ft_convert_base(char *nbr, char *base_from, char *base_to){
	if(!(check_base(base_from) && check_base(base_to)))
		return ((void *) 0);
	return convert_to_a_base(ft_atoi_base(nbr, base_from), base_to);
	 
}

/*
int main(int ac, char *av[]){
	if (ac == 4)
		printf("%s", ft_convert_base(av[1], av[2], av[3]));
}
*/
