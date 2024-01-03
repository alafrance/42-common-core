#include <stdlib.h>
int		ft_ultimate_range(int **range, int min, int max){
	int *tab;
	int i;

	i = 0;
	if(min >= max){
		*range = (void *)0;
		return 0;
	}
	if (!(tab = malloc(sizeof(int) * (max - min)))){
		return 0;
	}
	while(min != max){
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (max - min);
}
/*
#include <stdio.h>
int main(){
	int min;
	int max;
	int i;
	int *range;

	i = 0;
	min = 123;
	max = 7;
	ft_ultimate_range(&range, min, max);
	if(min > max){
		printf("%ls", range);
	}else{
		while(i != max - min){
			printf("%d\n", range[i]);
			i++;
		}
	}
	return 0;
}
*/
