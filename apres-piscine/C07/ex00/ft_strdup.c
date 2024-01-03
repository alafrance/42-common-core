#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str){
	int i;

	i = 0;

	while(str[++i]);
	return i;
}
char *ft_strdup(char *src){
	int i;
	char *dest;

	i = 0;
	if(!(dest = malloc(sizeof(char) * ft_strlen(src) + sizeof(char)))){
			return NULL;
	}
	while(src[i]){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}


/*
#include <stdio.h>
int main(int ac, char *av[] ){
	char *dest;
	char src[6] = "coucou";	
	dest = ft_strdup(src);
	return 0;
}
*/
