# include "Phonebook.hpp"
# include <iostream>

int main() {
	std::string buf = "";
	bool loop = true;
	Phonebook phonebook;
	std::cout << "Welcome to Phonebook, commands available: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "Phonebook > ";
	while (std::getline(std::cin, buf) && buf != "EXIT" && buf != "exit") {
		if (buf == "ADD") {
			phonebook.ft_add();
		} else if (buf ==  "SEARCH") {
			phonebook.ft_search();
		} else if (buf ==  "EXIT") {
			loop = false;
		}
		buf = "";
		std::cout << "Phonebook > ";
	}
}