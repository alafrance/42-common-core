//
// Created by Alexis Lafrance on 25/09/2021.
//

#include "Bureaucrat.hpp"
/* CANONICAL FORM */
Bureaucrat::Bureaucrat(): _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHigh;
	else if (grade > 150)
		throw GradeTooLow;
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName()) {
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &inst) {
	_grade = inst.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}
/* ACCESSORS */

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

/* MAIN */

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHigh;
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLow;
	_grade++;
}

void Bureaucrat::signForm(const AForm &form) {
	if (form.getIsSigned())
		std::cout << _name << " signs " << form.getName() << std::endl;
	else
		std::cout << _name << " cannot sign " << form.getName() << " because :" << std::endl;
}

void Bureaucrat::executeForm(const AForm &form) {
	form.execute(*this);
	std::cout << getName() << " executes " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << "name: " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade();
	return os;
}