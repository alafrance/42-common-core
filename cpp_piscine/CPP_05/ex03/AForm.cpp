//
// Created by Alexis Lafrance on 25/09/2021.
//

#include "AForm.hpp"

/* CANONICAL FORM */
AForm::AForm(void): name(""), isSigned(0), gradeToSigned(1), gradeToExecuted(1)  {}

AForm::AForm(const std::string &name, bool isSigned, const int gradeToSigned, const int gradeToExecuted):
name(name), isSigned(isSigned), gradeToSigned(gradeToSigned), gradeToExecuted(gradeToExecuted) {
	if (gradeToSigned > 150 || gradeToExecuted > 150)
		throw GradeTooLow;
	if (gradeToSigned < 1 || gradeToExecuted < 1)
		throw GradeTooHigh;
}

AForm::~AForm(void) {}

AForm::AForm(AForm const &src): name(""), gradeToSigned(1), gradeToExecuted(1) {
	*this = src;
}

AForm &AForm::operator=(AForm const &inst) {
	isSigned = inst.isSigned;
	return (*this);
}

/* ACCESSORS */

const std::string &AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSigned() const {
	return gradeToSigned;
}

int AForm::getGradeToExecuted() const {
	return gradeToExecuted;
}


std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "name: " << form.getName() << " isSigned: " << form.getIsSigned() << " gradeToSigned: " << form.getGradeToSigned()
	   << " gradeToExecuted: " << form.getGradeToExecuted();
	return os;
}

/* MAIN */

void AForm::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSigned)
	{
		bureaucrat.signForm(*this);
		throw GradeTooLow;
	}
	isSigned = true;
	bureaucrat.signForm(*this);
}

void AForm::testExecute(int grade) const {
	if (!this->isSigned)
		throw AForm::IsNotSignedException();
	if (this->gradeToExecuted < grade)
	{
		std::cout << "GradeToExecuted : \n";
		throw AForm::GradeTooLowException();
	}
}

