#include "Dog.hpp"
#include <iostream>

Dog::Dog(void){
	std::cout << "Default constructor called (Dog)\n";
	_type = "Dog";

}

Dog::~Dog(void){
	std::cout << "Destructor called (Dog)\n";

}

Dog::Dog(Dog const& src){
	*this = src;
}

Dog&	Dog::operator=(Dog const& rhs){
	_type = rhs._type;
	return *this;
}

/* MAIN */
void	Dog::makeSound() const{
	std::cout << "OUAAAAF !\n";
}