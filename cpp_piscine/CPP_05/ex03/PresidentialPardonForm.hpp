//
// Created by Alexis Lafrance on 26/09/2021.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
private:
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &inst);
	virtual void 				execute(Bureaucrat const & executor) const;
};

#endif //EX02_PRESIDENTIALPARDONFORM_HPP
