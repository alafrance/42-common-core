#include <stdlib.h>
int *ft_map(int *tab, int length, int(*f)(int)){
	int i;
	int *tab_2;
	tab_2 = malloc(sizeof(int) * length);
	i = 0;
	while(i != length){
		tab_2[i] = f(tab[i]);
		i++;
	}
	return tab_2;
}


/*
int multiply_2(int nb){
	return nb * 2;
}

#include <stdio.h>
int main(){
	int tab[] = {1, 2, 3, 4, 5};
	int *other_tab = ft_map(tab, 5, &multiply_2);
	printf("%d %d %d %d %d\n", other_tab[0], other_tab[1], other_tab[2], other_tab[3], other_tab[4]);
	printf("%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
	return 0;
}
*/
