//
// Created by Alexis Lafrance on 25/09/2021.
//

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	name;
	bool				isSigned;
	const int 			gradeToSigned;
	const int 			gradeToExecuted;
public:
	Form();
	Form(Form const &src);
	Form(const std::string &name, bool isSigned, const int gradeToSigned, const int gradeToExecuted);
	virtual ~Form();
	Form &operator=(Form const &inst);
	const std::string 	&getName() const;
	bool				getIsSigned() const;
	int					getGradeToSigned() const;
	int					getGradeToExecuted() const;
	void 				beSigned(Bureaucrat bureaucrat);
	class GradeTooLowException : public std::exception {
	public:
		const char * what () const throw ()
		{
			return "Your grade is too low (grade <= 150)";
		}
	} GradeTooLow;
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw () {
			return "Your grade is too high (grade >= 1)";
		}
	} GradeTooHigh;
};
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //EX01_FORM_HPP
