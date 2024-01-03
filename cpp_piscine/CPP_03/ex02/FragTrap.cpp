#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	_hitpoints = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Constructor called  (FragTrap)" << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name){
	_hitpoints = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Name constructor called (FragTrap)" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) {
	*this = src;
}

FragTrap::~FragTrap(void){
	std::cout << "Destructor called (FragTrap)" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "I'm positive high fives request on the standard ouput. I describe EVERYTHING !\n";
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_energyPoint = rhs._energyPoint;
	_attackDamage = rhs._attackDamage;
	return (*this);
}
