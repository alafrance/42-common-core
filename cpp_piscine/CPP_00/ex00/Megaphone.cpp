# include <iostream>
# include <cctype>

int main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1 ; i < ac ; i++) {
			for (int j = 0; av[i][j]; j++ ){
				char c = toupper(av[i][j]);
				std::cout << c;
			}
		}
		std::cout << std::endl;
	}
	return(0);
}