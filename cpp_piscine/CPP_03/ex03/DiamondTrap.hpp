#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
public:
	DiamondTrap();
	DiamondTrap(const std::string);
	~DiamondTrap();
	void whoAmI() const;
	void attack(std::string const & target);
private:
	std::string	_name;
};

#endif