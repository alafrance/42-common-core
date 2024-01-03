#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(void): _name(""){
	_hitpoints = FragTrap::_hitpoints;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Constructor called (Diamond Trap)" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name){
	_hitpoints = FragTrap::_hitpoints;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Name constructor called (Diamond Trap)" << std::endl;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "Destructor called (Diamond Trap)" << std::endl;
}

void DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	std::cout << "\n--- DIAMONDTRAP : WHO AM I ---\n";
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	std::cout << "name: " << _name << ", hitpoints: " << _hitpoints << ", energyPoint: " << _energyPoint << " and attackDamage: " << _attackDamage << std::endl;
	std::cout << "--- DIAMONDTRAP : WHO AM I ---\n\n";
}