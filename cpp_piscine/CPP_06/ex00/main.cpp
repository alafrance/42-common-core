#include <iostream>
#include <cmath>

bool 	isDigitStr(std::string str) {
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	for ((void)i; i < str.length(); ++i) {
		if (!(str[i] == 'f' && i + 1 == str.length())) {
			if (!isdigit(str[i]) && str[i] != '.')
				return (false);
		}
	}
	return (true);
}

bool specialCase(std::string str) {
	return (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan");
}

int main(int ac, char **av) {
	double a;
	bool isSpecialCase;
	if (ac != 2)
	{
		std::cout << "ERROR ARGUMENT" << std::endl;
		return (0);
	}
	std::string str = av[1];
	isSpecialCase = specialCase(str);
	if (!isDigitStr(str) && !isSpecialCase) {
		if (str.length() != 1) {
			std::cout << "Error : Need to be literal Value\n";
			return (0);
		}
		a = static_cast<double>(str[0]);
	}
	else
		a = atof(av[1]);
	std::cout << "char: ";
	char c = static_cast<char>(a);
	if (isSpecialCase || a > std::numeric_limits<char>::max() || a < std::numeric_limits<char>::min())
		std::cout << "impossible\n";
	else if (a < 32 || a >= 127 )
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: ";
	if (isSpecialCase || a > std::numeric_limits<int>::max() || a < std::numeric_limits<int>::min())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(a) << std::endl;
	std::cout << "float: " << static_cast<float>(a);
	if (!static_cast<bool>(std::fmod(a, 1)))
		std::cout << ".0";
	std::cout << "f\n";
	std::cout << "double: " << static_cast<double>(a);
	if (!static_cast<bool>(std::fmod(a, 1)))
		std::cout << ".0";
	std::cout << std::endl;
	return 1;
}