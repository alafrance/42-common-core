int ft_is_sort(int *tab, int length, int(*f)(int, int)){
	int i;
	int order;

	i = 0;
	order = 0;
	while(i != length - 1 && order == 0){
		if(f(tab[i], tab[i + 1]) < 0)
			order = 1;
		else if(f(tab[i], tab[i + 1]) > 0)
			order = -1;
		i++;
	}
	if(length == 1 || order == 0)
		return 1;
	while(i != length - 1){
		if(f(tab[i], tab[i + 1]) < 0 && order == -1 
			|| f(tab[i], tab[i + 1]) > 0 && order == 1)
			return 0;
		i++;
	}
	return 1;
}
/*
int int_cmp(int a, int b){
	return a - b;
}
#include <stdio.h>
int main(){

//	int tab[] = {1, 2, 3, 4, 5, 6};
//	int tab[] = {6, 5, 4, 3, 2, 1};
	int tab[] = {1};
	printf("ft_is_sort: %d", ft_is_sort(tab, 1, int_cmp));
}
*/
