//
// Created by Alexis Lafrance on 25/09/2021.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat {
private:
	std::string const	_name;
	int 				_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(Bureaucrat const& src);
	virtual ~Bureaucrat();
	Bureaucrat&	operator=(Bureaucrat const& inst);
	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form const& form);
	class GradeTooLowException : public std::exception {
	public:
		const char * what () const throw ()
		{
			return "Your grade is too low (grade <= 150)";
		}
	} GradeTooLow;
	class GradeTooHighException : public std::exception {
	public:
		const char * what () const throw ()
		{
			return "Your grade is too high (grade >= 1)";
		}
	} GradeTooHigh;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif //EX00_BUREAUCRAT_HPP
