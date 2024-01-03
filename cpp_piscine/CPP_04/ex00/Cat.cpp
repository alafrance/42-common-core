#include "Cat.hpp"
#include <iostream>
/* CANONICAL FORM */
Cat::Cat(void){
	_type = "Cat";
	std::cout << "Default constructor called (Cat)\n";

}

Cat::~Cat(void){
	std::cout << "Destructor called (Cat)\n";

}

Cat::Cat(Cat const& src){
	*this = src;
}

Cat&	Cat::operator=(Cat const& rhs){
	_type = rhs._type;
	return *this;
}

/* MAIN */
void	Cat::makeSound() const{
	std::cout << "MIAOUUUUH\n";
}