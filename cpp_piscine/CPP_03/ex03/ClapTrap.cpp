#include "ClapTrap.hpp"

/* CONSTRUCTOR */
ClapTrap::ClapTrap(void): _name(""), _hitpoints(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Constructor called (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Name constructor called (ClapTrap)" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destructor called (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src){
	std::cout << "Copy Constructor called (ClapTrap)" << std::endl;
	*this = src;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs){
	std::cout << "Assignation Operator overload called (ClapTrap)" << std::endl;
	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_energyPoint = rhs._energyPoint;
	_attackDamage = rhs._attackDamage;
	return *this;
}


/* CODE */
void ClapTrap::attack(std::string const & target) {
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount <= 0)
	{
		std::cout << "Attack failed\n";
		return ;
	}
	std::cout << _name << " take damage ! -" << amount << "hp!!!\n";
	_hitpoints -= amount;
	std::cout << _name << " hp: " << _hitpoints << std::endl;
	if (_hitpoints < 0)
		std::cout << _name << " DIE ! GAME OVER...\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (amount <= 0)
	{
		std::cout << "Repaired failed\n";
		return ;
	}
	std::cout << _name << " gain " << amount << " hitpoints !\n";
	_hitpoints += amount;
	std::cout << _name << " hp: " << _hitpoints << std::endl;
}


/* ACCESSORS */

std::string		ClapTrap::getName() const {
	return (_name);
}

void		ClapTrap::setName(std::string name) {
	_name = name;
}

int			ClapTrap::getHitpoints() const {
	return (_hitpoints);
}

void		ClapTrap::setHitpoints(int hp) {
	_hitpoints = hp;
}

int			ClapTrap::getEnergyPoints() const {
	return (_energyPoint);
}

void		ClapTrap::setEnergyPoints(int energyPoint) {
	_energyPoint = energyPoint;
}

int			ClapTrap::getAttackDamage() const {
	return (_attackDamage);
}

void		ClapTrap::setAttackDamage(int AttackDamage) {
	_attackDamage = AttackDamage;
}
