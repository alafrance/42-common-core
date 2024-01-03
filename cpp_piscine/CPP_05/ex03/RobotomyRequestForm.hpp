//
// Created by Alexis Lafrance on 26/09/2021.
//

#ifndef EX02_ROBOTOMYREQUESTFORM_HPP
#define EX02_ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
private:
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm();
	virtual void 		execute(Bureaucrat const & executor) const;
	RobotomyRequestForm &operator=(RobotomyRequestForm const &inst);
};

#endif //EX02_ROBOTOMYREQUESTFORM_HPP
