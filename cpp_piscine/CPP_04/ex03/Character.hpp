#ifndef Character_HPP
#define Character_HPP
#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter {
public:
	Character();
	Character(Character const& src);
	Character(std::string name);
	virtual ~Character();

	Character& operator=(Character const& rhs);
	virtual void equip(AMateria* materia);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	virtual std::string const &	getName() const;
private:
	std::string _name;
	AMateria	**_inventory;
};

#endif