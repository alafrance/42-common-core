#ifndef _FT_OPTION_C
#define _FT_OPTION_C

int is_c_option(char *str){
	return (str[0] == '-' && str[1] == 'c' && ft_strlen(str) == 2)? 1 : 0;
}


int is_option(char **av, int ac){
	int i;

	i = 1;
	while(i != ac){
		if(is_c_option(av[i]) && i + 1 < ac){
			if(ft_str_is_numeric(av[i + 1]))
				return 1;
		}
		i++;
	}
	return 0;
}
int isnt_a_option(char **av, int ac){
	int i;

	i = 1;
	while(i != ac){
		if(is_c_option(av[i]) && i + 1 >= ac){
			return 1;
		}
		i++;
	}
	return 0;
}

char *option(char **av, int ac){
	int i;

	i = 1;
	while(i != ac){
		if(is_c_option(av[i]) && i < ac ){
			if(ft_str_is_printable(av[i + 1]))
				return av[i + 1];
		}
		i++;
	}
	return "0";
}
#endif
