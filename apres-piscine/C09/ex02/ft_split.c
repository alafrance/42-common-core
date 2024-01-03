#include <stdlib.h>

int is_whitespace(char c){
    if(c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}
int     ft_strlen(char *str){
    int i;
    
    i = 0;
    while(str[++i]);
    return i;
}
int is_empty(char *str){
	return (str[0] == '\0' || (is_whitespace(str[0]) && ft_strlen(str) == 1)) ? 1 : 0;
}

char *malloc_word(char *str, int start, int end){
	char *word;
	int i;

	i = 0;
	word = (char*)malloc(sizeof(char *) * (end - start + 1));
	while(start != end + 1){
		word[i] =  str[start];
		start++;
		i++;
	}
	word[i++] = '\0';
	return word;
}

int count_words(char *str, char *charset){
	int count;
	int i;
	int j;
	int remember;	
	j = 0;
	i = 0;
	if(str[i] == '\0')
		return 0;
	count = 1;
	remember = i;
	while(str[i]){
		if(str[i] == charset[j]){
			while(str[i] && str[i] == charset[j] && charset[j]){
				i++;
				j++;
			}
			if(charset[j] == '\0'){
				if(!is_empty(malloc_word(str, remember, i - ft_strlen(charset) - 1))){
					count++;
					remember = i;
				}
			}
			j = 0;
		}else
			i++;
	}
	return count;
}
int presence_of_charset(char *str, int start, char *charset){

	int i;
	int j;

	i = start;
	j = 0;
	while(str[i]){
		if(str[i] == charset[j]){
			while(str[i] == charset[j] && str[i] && charset[j]){
				i++;	
				j++;
			}
			if(charset[j] == '\0'){
				return i - j - 1;
			}
			j = 0;
		}
		i++;
	}
	return 0;
}

char **ft_split(char *str, char *charset){
	char **result;
	int i;
	int j;
	int remember;

	i = 0;
	remember = 0;
	j = 0;
	if (!(result = malloc(sizeof(char *) * count_words(str, charset) + 1)))
		return (void * )0;
	while(str[i] && presence_of_charset(str, i, charset) != 0){
		remember = i;
	 	i = presence_of_charset(str, i, charset);
		if(!is_empty(malloc_word(str, remember, i)))
			result[j++] = malloc_word(str, remember, i);
		i = i + ft_strlen(charset) + 1;
	}
	result[j] = malloc_word(str, i, ft_strlen(str) - 1);
	j++;
	result[j] = NULL;
	return result;
}

#include <stdio.h>
#include <string.h>

int main(int ac, char *av[]){
	char **result;
	char *word;
	int i;

	i = 0;
	if(ac == 3){
		result = ft_split(av[1], av[2]);
		while(result[i] != NULL){
			printf("%s\n", result[i++]);
		}
	}
}
