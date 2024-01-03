//
// Created by Alexis Lafrance on 9/27/21.
//

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* CANONICAL FORM */
Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern &Intern::operator=(Intern const &inst) {
	(void) inst;
	return (*this);
}

AForm *Intern::makeForm(std::string request, std::string target) {
	AForm* form;
	std::string	request_str[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i = 0;

	for (i = 0; i < 3; ++i) {
		if (request_str[i] == request)
			break;
	}
	switch (i) {
		case 0:
			form = new RobotomyRequestForm(target);
			break;
		case 1:
			form = new ShrubberyCreationForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw RequestForm;
	}
	std::cout << "Intern creates " << target << std::endl;
	return (form);
}

/* ACCESSORS */

/* MAIN */
