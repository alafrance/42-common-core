#include "Contact.hpp"
# include <iostream>

Contact::Contact(){
}

bool	Contact::_isDigit(std::string str) {
	for (unsigned long i = 0 ; i < str.size() ; i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

std::string    Contact::input(std::string prompt, bool need_number) {
	std::string buf;

	std::cout << prompt;
	while (std::getline(std::cin, buf))
		if ((need_number && !_isDigit(buf)) || buf == "")
			std::cout << "Wrong input" << std::endl << prompt;
		else
			break;
	return buf;
}

void    Contact::initContact() {
	setFirstname(input("Firstname : ", 0));
	setLastname(input("Lastname : ", 0));
	setNickname(input("Nickname : ", 0));
	setPhoneNumber(atoi(input("Phone number : ", 1).c_str()));
	setDarkestSecret(input("Darkest secret : ", 0));
}

void    Contact::displayContact() {
	std::cout << "Firstname : " << getFirstname() << std::endl;
	std::cout << "Lastname : " << getLastname() << std::endl;
	std::cout << "Nickname : " << getNickname() << std::endl;
	std::cout << "Phone number : " << getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << getDarkestSecret() << std::endl;
}

std::string Contact::getFirstname() const {
	return _firstname;
}

std::string Contact::getLastname() const {
	return _lastname;
}

std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}

std::string Contact::getNickname() const {
	return _nickname;
}

int 		Contact::getPhoneNumber() const {
	return _phoneNumber;
}

void 		Contact::setFirstname(std::string firstname){
	_firstname =  firstname;
}

void 		Contact::setLastname(std::string lastname) {
	_lastname = lastname;
}

void 		Contact::setDarkestSecret(std::string darkest_secret) {
	_darkestSecret = darkest_secret;
}

void 		Contact::setNickname(std::string nickname) {
	_nickname = nickname;
}

void 		Contact::setPhoneNumber(int phone_number) {
	_phoneNumber = phone_number;
}
