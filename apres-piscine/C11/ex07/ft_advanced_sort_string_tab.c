void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *)){
	int i;
	int j;
	char *tmp;
	j = 0;
	i = 0;
	while(tab[i + 1] != (void*)0){
		while(tab[j + 1] != (void*)0){
			if(cmp(tab[j], tab[j + 1]) > 0){
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
