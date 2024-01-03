int ft_count_if(char **tab, int length, int(*f)(char*)){
	int i;
	int count;

	count = 0;
	i = 0;
	while(i != length){
		if(f(tab[i]) != 0)
			count++;
		i++;
	}
	return count;
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
	printf("%d", ft_count_if(av + 1, ac - 1, is_present_char_a));
}
*/
