//
// Created by Alexis Lafrance on 25/09/2021.
//
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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

int main() {
	try {
		Bureaucrat bureaucrat(initBureauCrat());
		std::cout << "Bureaucrat created ! " << bureaucrat << " and grade : " << bureaucrat.getGrade() << std::endl;
		std::cout << "Well done ! Your works increases your grade !\n";
		bureaucrat.incrementGrade();
		std::cout << "Your grade : " << bureaucrat.getGrade() << std::endl;
		std::cout << "Oh my god ! Karen tells to your boss that you forgot a rendez-vous !\n";
		bureaucrat.decrementGrade();
		std::cout << "Your grade : " << bureaucrat.getGrade() << std::endl;
		Intern someRandomIntern;
		AForm *rff = someRandomIntern.makeForm("robotomy request", "Bender");
		rff->beSigned(bureaucrat);
		rff->execute(bureaucrat);
		delete rff;
		AForm *rf2 = someRandomIntern.makeForm("blablou", "bliblou");
		rf2->beSigned(bureaucrat);
		rf2->execute(bureaucrat);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::IsNotSignedException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::RequestFormException& e) {
		std::cout << e.what() << std::endl;
	}
}


