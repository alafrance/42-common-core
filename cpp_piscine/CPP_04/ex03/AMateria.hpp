#ifndef AMateria_HPP
#define AMateria_HPP
#include <iostream>

class ICharacter;
class AMateria {
private:
protected:
	std::string _type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const& src);
	virtual ~AMateria();

	AMateria& operator=(AMateria const& rhs);
	std::string const &getType();

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif