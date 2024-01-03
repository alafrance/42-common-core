#include "Animal.hpp"

/* CANONICAL FORM */
Animal::Animal(void): _type(""){
	std::cout << "Default constructor called (Animal)\n";
}

Animal::~Animal(void){
	std::cout << "Destructor called (Animal)\n";
}

Animal::Animal(Animal const& src){
	*this = src;
}

Animal&	Animal::operator=(Animal const& rhs){
	std::cout << "HEEEEEEEEEELLLLLOOOOOO\n";
	_type = rhs._type;
	return *this;
}

/* ACCESSORS */
std::string		Animal::getType() const {
	return _type;
}

/* MAIN */
void	Animal::makeSound() const{

}