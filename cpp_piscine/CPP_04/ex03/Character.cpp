#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
/* CANONICAL FORM */
Character::Character(void){
	_inventory = new AMateria*[4];
	for (int i = 0 ; i < 4 ; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name){
	_name = name;
	_inventory = new AMateria*[4];
	for (int i = 0 ; i < 4 ; i++)
		_inventory[i] = NULL;
}

Character::~Character(void){
	for (int i = 0 ; i < 4 ; i++)
		if (_inventory[i])
			delete _inventory[i];
	delete[] _inventory;
}

Character::Character(Character const& src){
	*this = src;
}

Character&	Character::operator=(Character const& rhs){
	_name = rhs._name;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}
/* ACCESSORS */

std::string const &	Character::getName() const {
	return	_name;
}
/* MAIN */

void	Character::equip(AMateria *materia) {
	for (int i = 0 ; i < 4 ; i++)
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			return ;
		}

}

void Character::unequip(int idx) {
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	_inventory[idx]->use(target);
}