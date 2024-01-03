int ft_any(char **tab, int (*f)(char*)){
	int i;

	i = 0;
	while(tab[i] != (void*)0){
		if(f(tab[i]) != 0)
			return 1;
		i++;
	}
	return 0;
}

/*
int is_present_char_a(char *str){
	int i;

	i = 0;
	while(str[i]){
		if(str[i] == 'a')
			return 1;
		i++;
	}
	return 0;
}


#include <stdio.h>
int main(int ac, char **av){
	printf("%d", ft_any(av + 1, is_present_char_a));
}
*/
