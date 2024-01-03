//
// Created by Alexis Lafrance on 9/27/21.
//

#ifndef EX03_INTERN_HPP
#define EX03_INTERN_HPP
#include <iostream>
#include "AForm.hpp"
class Intern
{
private:
public:
	Intern();
	Intern(Intern const &src);
	virtual ~Intern();
	Intern &operator=(Intern const &inst);
	AForm* makeForm(std::string request, std::string target);
class RequestFormException: public std::exception {
public:
	const char * what () const throw () {
		return "Your request doesn't exist";
	}
}	RequestForm;
};

#endif //EX03_INTERN_HPP
