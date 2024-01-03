#ifndef Ice_HPP
#define Ice_HPP
#include "AMateria.hpp"
class Ice: public AMateria {
public:
	Ice();
	Ice(Ice const& src);
	virtual ~Ice();

	Ice& operator=(Ice const& rhs);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target); // need to test whitout proto
private:
	
};

#endif