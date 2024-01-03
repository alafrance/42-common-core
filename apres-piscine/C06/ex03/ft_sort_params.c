#include <unistd.h>

void ft_putchar(char c){
	write(1, &c, 1);
}
void ft_putstr(char *str){
	int i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);

}

int ft_strlen(char *str){
	int i;

	i = 0;
	while(str[++i]);
	return i;
}

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

void ft_rev_params(char *tab[], int size){
	int i;
	int j;
	char *swap;
	i = 1;
	j = 1;
	while(i != size){
		while(j != size){
			if(ft_strcmp(tab[j + 1], tab[j]) < 0){
				swap = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

int main(int ac, char *av[]){
	int i;

	i = 1;
	if (ac > 2){
		ft_rev_params(av, ac - 1);
	}
	while(i != ac){
		ft_putstr(av[i]);
		i++;
		ft_putchar('\n');
	}
}
