//
// Created by Alexis Lafrance on 25/09/2021.
//

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	name;
	bool				isSigned;
	const int 			gradeToSigned;
	const int 			gradeToExecuted;
public:
	AForm();
	AForm(AForm const &src);
	AForm(const std::string &name, bool isSigned, const int gradeToSigned, const int gradeToExecuted);
	virtual ~AForm();
	AForm &operator=(AForm const &inst);
	const std::string 	&getName() const;
	bool				getIsSigned() const;
	int					getGradeToSigned() const;
	int					getGradeToExecuted() const;
	void 				beSigned(Bureaucrat bureaucrat);
	void				testExecute(int grade) const;
	virtual void 		execute(Bureaucrat const & executor) const = 0;
	class GradeTooLowException : public std::exception {
	public:
		const char * what () const throw ()
		{
			return "Your grade is too low";
		}
	} GradeTooLow;
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw () {
			return "Your grade is too high";
		}
	} GradeTooHigh;
	class IsNotSignedException : public std::exception {
	public:
		const char* what() const throw () {
			return "Your form is not signed";
		}
	};
};
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif //EX01_FORM_HPP
