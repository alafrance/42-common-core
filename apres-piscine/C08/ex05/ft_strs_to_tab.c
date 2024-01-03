#include "ft_stock_str.h"
#include <stdlib.h>
int ft_strlen(char *str){
	int i;

	i = 0;
	while(str[++i]);
	return i;
}
char				*ft_strdup(char *src)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av){
	struct s_stock_str *ar_stock;
	int i;

	i = 0;
	if (!(ar_stock = malloc(sizeof(struct s_stock_str) * (ac + 1)))){
		free(ar_stock);
		return NULL;	
	}
	
	while(i != ac){
		ar_stock[i].size = ft_strlen(av[i]);
		ar_stock[i].str = av[i];
		ar_stock[i].copy = ft_strdup(av[i]);	
		i++;
	}
	ar_stock[i].str = 0;
	return ar_stock;
}
