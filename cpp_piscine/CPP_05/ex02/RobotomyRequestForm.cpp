//
// Created by Alexis Lafrance on 26/09/2021.
//

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

/* CANONICAL FORM */
RobotomyRequestForm::RobotomyRequestForm(void): AForm("unknown", 0, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 0, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src) {
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &inst) {
	(void) inst;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	testExecute(executor.getGrade());
	srand((unsigned) time(0));
	int randomNumber = rand() % 2;
	if (randomNumber == 0)
		std::cout << getName() << " has been robotomized successfully\n";
	else
		std::cout << "Error 404.... " << getName() << " have a big error\n";
	(void)executor;
}

/* ACCESSORS */

/* MAIN */
