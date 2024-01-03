#include "Dog.hpp"
#include <iostream>

Dog::Dog(void){
	std::cout << "Default constructor called (Dog)\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog(void){
	std::cout << "Destructor called (Dog)\n";
	delete _brain;
}

Dog::Dog(Dog const& src){
	*this = src;
}

Dog&	Dog::operator=(Dog const& rhs){
	std::cout << "Operator = overload (Dog)\n";
	_type = rhs._type;
	_brain = new Brain(*rhs._brain);
	return *this;
}

/* ACCESSSORS */
Brain*	Dog::getBrain() const {
	return _brain;
}

void	Dog::setBrain(Brain* brain) {
	if (_brain)
		delete _brain;
	_brain = brain;
}

/* MAIN */
void	Dog::makeSound() const{
	std::cout << "OUAAAAF !\n";
}