#include "AMateria.hpp"
#include "ICharacter.hpp"
/* CANONICAL FORM */
AMateria::AMateria(void){

}

AMateria::AMateria(std::string const & type) {
	_type = type;
}

AMateria::~AMateria(void){

}

AMateria::AMateria(AMateria const& src){
	*this = src;
}

AMateria&	AMateria::operator=(AMateria const& rhs){
	// _type = rhs._type;
	(void)rhs;
	return *this;
}
/* ACCESSORS */

std::string const &AMateria::getType() {
	return (_type);
}

/* MAIN */

void AMateria::use(ICharacter& target) {
	std::cout << "Use" << _type << " at " << &target.getName();
}