#include "WrongAnimal.hpp"

/* CANONICAL FORM */
WrongAnimal::WrongAnimal(void): _type(""){
	std::cout << "Default constructor called (WrongAnimal)\n";
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "Destructor called (WrongAnimal)\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const& src){
	*this = src;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs){
	_type = rhs._type;
	return *this;
}

/* ACCESSORS */
std::string		WrongAnimal::getType() const {
	return _type;
}

/* MAIN */
void	WrongAnimal::makeSound() const{

}