#include <stdlib.h>
int		*ft_range(int min, int max){
	int *tab;
	int i;

	i = 0;
	if(min >= max){
		return (void *)0;
	}
	if (!(tab = malloc(sizeof(int) * (max - min)))){
		return (void *)0;
	}
	while(min != max){
		tab[i] = min;
		min++;
		i++;
	}
	return tab;
}

/*
#include <stdio.h>
int main(int ac, char *av[]){
	int *tab;
	int i;
	int min;
	int max;

	min = 4;
	max = 10;
	i = 0;
	tab = ft_range(min, max);
	if (min > max){
		printf("%ls", tab);
	}else{
		while(i != max - min){
			printf("%d\n", tab[i]);
			i++;
		}
	}
}
*/
