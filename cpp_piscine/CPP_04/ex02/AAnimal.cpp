#include "AAnimal.hpp"

/* CANONICAL FORM */
AAnimal::AAnimal(void): _type(""){
	std::cout << "Default constructor called (AAnimal)\n";
}

AAnimal::~AAnimal(void){
	std::cout << "Destructor called (AAnimal)\n";
}

AAnimal::AAnimal(AAnimal const& src){
	*this = src;
}

AAnimal&	AAnimal::operator=(AAnimal const& rhs){
	std::cout << "HEEEEEEEEEELLLLLOOOOOO\n";
	_type = rhs._type;
	return *this;
}

/* ACCESSORS */
std::string		AAnimal::getType() const {
	return _type;
}