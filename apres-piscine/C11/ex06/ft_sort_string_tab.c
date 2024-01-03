int ft_strcmp(char *s1, char *s2){
    int i;
    i = 0;
    while (s1[i]){
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

void ft_sort_string_tab(char **tab){
	int i;
	int j;
	char *tmp;
	j = 0;
	i = 0;
	while(tab[i + 1] != (void*)0){
		while(tab[j + 1] != (void*)0){
			if(ft_strcmp(tab[j], tab[j + 1]) > 0){
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av){
	char **tab;
	tab = malloc(sizeof(char*) * 4);
   	tab[0]	= "heyo";
   	tab[1]	= "heye";
   	tab[2]	= "heyi";
   	tab[3] = NULL;	
	printf("%s, %s, %s\n", tab[0], tab[1], tab[2]);
	ft_sort_string_tab(tab);
	printf("%s, %s, %s\n", tab[0], tab[1], tab[2]);
}
*/
