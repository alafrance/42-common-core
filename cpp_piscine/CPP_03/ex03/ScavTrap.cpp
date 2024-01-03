#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	std::cout << "Constructor called (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
	std::cout << "Name constructor called (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) {
	*this = src;
}

ScavTrap::~ScavTrap(void){
	std::cout << "Destructor called (ScavTrap)" << std::endl;
}

void ScavTrap::attack(std::string const & target) {
	std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode\n";
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_energyPoint = rhs._energyPoint;
	_attackDamage = rhs._attackDamage;
	return (*this);
}
