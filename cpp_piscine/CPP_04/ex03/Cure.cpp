#include "Cure.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
/* CANONICAL FORM */
Cure::Cure(void){
	_type = "cure";
}

Cure::~Cure(void){

}

Cure::Cure(Cure const& src){
	*this = src;
}

Cure&	Cure::operator=(Cure const& rhs){
	(void)rhs;
	return *this;
}

AMateria* Cure::clone() const {
	return (new Cure);
}

/* ACCESSORS */

/* MAIN */

void Cure::use(ICharacter& target) {
	std::cout << "* heals" << target.getName() << "'s wounds *\n";
}