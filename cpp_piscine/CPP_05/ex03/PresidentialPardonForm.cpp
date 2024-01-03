//
// Created by Alexis Lafrance on 26/09/2021.
//

#include "PresidentialPardonForm.hpp"

/* CANONICAL FORM */
PresidentialPardonForm::PresidentialPardonForm(void): AForm("unknown", 0, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 0, 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): AForm(src){
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &inst) {
	(void) inst;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	testExecute(executor.getGrade());
	std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox\n";
}

/* ACCESSORS */

/* MAIN */