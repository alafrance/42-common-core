#include "Cat.hpp"
#include <iostream>

/* CANONICAL FORM */
Cat::Cat(void){
	_type = "Cat";
	std::cout << "Default constructor called (Cat)\n";
	_brain = new Brain();
}

Cat::~Cat(void){
	std::cout << "Destructor called (Cat)\n";
	delete _brain;
}

Cat::Cat(Cat const& src){
	*this = src;
}

Cat&	Cat::operator=(Cat const& rhs){
	std::cout << "Operator = overload (Cat)\n";
	_type = rhs._type;
	_brain = new Brain(*rhs._brain);
	return *this;
}

/* ACCESSSORS */
Brain*	Cat::getBrain() const {
	return _brain;
}

void	Cat::setBrain(Brain* brain) {
	if (_brain)
		delete _brain;
	_brain = brain;
}

/* MAIN */
void	Cat::makeSound() const{
	std::cout << "MIAOUUUUH\n";
}