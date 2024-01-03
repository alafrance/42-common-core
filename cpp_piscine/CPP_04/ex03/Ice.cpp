#include "Ice.hpp"
#include "ICharacter.hpp"
/* CANONICAL FORM */
Ice::Ice(void){
	_type = "ice";
}

Ice::~Ice(void){

}

Ice::Ice(Ice const& src){
	*this = src;
}

Ice&	Ice::operator=(Ice const& rhs){
	(void)rhs;
	return *this;
}

AMateria* Ice::clone() const {
	return (new Ice);
}
/* ACCESSORS */

/* MAIN */

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}