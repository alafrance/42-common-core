#include <stdlib.h>

int ft_strlen(char *str){
	int i;

	i = 0;
	while(str[++i]);
	return i;
}
int count_size_all(char **strs, int size, int size_sep){
	int i;
	int j;
	int count;

	count = 0;
	j = 0;
	i = 0;
	while(j != size){
		while(strs[j][i]){
			i++;
			count++;
		}
		j++;
		if (j != size){
			count += size_sep;
		}
		i = 0;
	}
	return count + 1;
}
char	*ft_strjoin(int size, char **strs, char *sep){
	int i;
	int j;
	int k;
	char *str;
	
	k = 0;
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * count_size_all(strs, size, ft_strlen(sep)));
	
	if (size == 0){
		free(str);
		return str;
	}
	while(j != size){
		while(strs[j][i]){
			str[k] = strs[j][i];
			i++;
			k++;
		}
		i = 0;
		j++;
		if( j != size){
				while(sep[i]){
					str[k] = sep[i];
					k++;
					i++;
				}
		}
		i = 0;
	}
	return str;
}

/*
#include <stdio.h>
#include <string.h>
int main(){
	char *strs[3] = {
		"j'aime",
		"trop",
		"les juifs"
	};
	char *str;

	char sep[2] = "-";

	str = ft_strjoin(3, strs, sep);
	//printf("%d\n", count_size_all(strs, 3, ft_strlen(sep)));
	//printf("%d\n", ft_strlen(strs[0]) + ft_strlen(sep) + ft_strlen(strs[1]) + ft_strlen(sep) + ft_strlen(strs[2]) + 1);
	printf("%s\n", str);
}
*/
