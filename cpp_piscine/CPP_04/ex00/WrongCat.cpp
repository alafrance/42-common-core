#include "WrongCat.hpp"
#include <iostream>
/* CANONICAL FORM */
WrongCat::WrongCat(void){
	_type = "WrongCat";
	std::cout << "Default constructor called (WrongCat)\n";

}

WrongCat::~WrongCat(void){
	std::cout << "Destructor called (WrongCat)\n";

}

WrongCat::WrongCat(WrongCat const& src){
	*this = src;
}

WrongCat&	WrongCat::operator=(WrongCat const& rhs){
	_type = rhs._type;
	return *this;
}

/* MAIN */
void	WrongCat::makeSound() const{
	std::cout << "MIAOUUUUH\n";
}