#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	nbContact = 0;
}

Contact* Phonebook::getContact(void) {
	return _Contact;
}

bool	Phonebook::_isDigit(std::string str) {
	for (unsigned long i = 0 ; i < str.size() ; i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

void Phonebook::ft_add(void) {
	_Contact[nbContact % 8].initContact();
	if (nbContact != 8)
		nbContact++;
}

void	Phonebook::print_format_string(std::string str) {
	int i = 0;

	for (i = 0 ; i < 8 ; i++)
	{
		if (str.size() <= (unsigned long)i)
			std::cout << " ";
		else
			std::cout << str[i];
	}
	if 	(str.size() > 10)
		std::cout << ".";
	else if (str.size() == 10)
		std::cout << str[9];
	else
		std::cout << " ";
	std::cout << "|";
}

void Phonebook::ft_search(void) {
	std::string buf;

	if (nbContact == 0)
		std::cout << "\e[0;31mNO CONTACT\e[0m" << std::endl;
	else
	{
		for (int i = 0; i < nbContact; i++)
		{
			std::cout << i << "         |";
			print_format_string(_Contact[i].getFirstname());
			print_format_string(_Contact[i].getLastname());
			print_format_string(_Contact[i].getNickname());
			std::cout << std::endl;
		}
	}
	std::cout << "Index of the desired entry : ";
	std::getline(std::cin, buf);
	if (atoi(buf.c_str()) < nbContact && _isDigit(buf))
		_Contact[std::atoi(buf.c_str())].displayContact();
	else
		std::cout << "Wrong index" << std::endl;
	
}