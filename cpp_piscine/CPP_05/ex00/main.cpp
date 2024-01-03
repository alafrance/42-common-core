#include <iostream>
#include "Bureaucrat.hpp"

bool	strIsDigit(std::string str) {
	size_t i = 0;
	if (str[0] == '-')
		i++;
	while (i < str.length()) {
		if (!isdigit(str[i])) {
			std::cout << "NEED TO BE A NUMBER\n";
			return (false);
		}
		i++;
	}
	return true;
}

std::string	askSomething(const std::string &input) {
	std::string buf;

	std::cout << input;
	while (std::getline(std::cin, buf) && buf.empty()) {
		std::cout << input;
	}
	return (buf);
}

int	askNumber(const std::string &input) {
	std::string buf;

	std::cout << input;
	while(std::getline(std::cin, buf) && (!strIsDigit(buf) || buf.empty())) {
		std::cout << input;
	}
	return (atoi(buf.c_str()));
}

Bureaucrat	initBureauCrat() {
	std::string name = askSomething("Your name : ");
	int			grade = askNumber("Your grade : ");
	Bureaucrat bureaucrat(name, grade);
	return(bureaucrat);
}

int main(){
	std::cout << "Hello ! Please enter your name and your grade : \n";
	try
	{
		Bureaucrat john(initBureauCrat());
		std::cout << "Bureaucrat created with name : " << john.getName() << " and grade : " << john.getGrade() << std::endl;
		std::cout << "Well done ! Your works increases your grade !\n";
		john.incrementGrade();
		std::cout << "Your grade : " << john.getGrade() << std::endl;
		std::cout << "Oh my god ! Karen tells to your boss that you forgot a rendez-vous !\n";
		john.decrementGrade();
		std::cout << "Your grade : " << john.getGrade() << std::endl;

	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
}
