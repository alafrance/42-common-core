//
// Created by Alexis Lafrance on 26/09/2021.
//

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP
#define EX02_SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
class ShrubberyCreationForm: public AForm {
private:
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
	virtual void 		execute(Bureaucrat const & executor) const;
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &inst);
};

#endif //EX02_SHRUBBERYCREATIONFORM_HPP
