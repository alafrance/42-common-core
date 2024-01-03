#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap();
	ScavTrap(const std::string name);
	~ScavTrap();
	ScavTrap& operator=(ScavTrap const& rhs);
	ScavTrap(ScavTrap const& src);
	void attack(std::string const & target);
	void guardGate();
private:
	
};

#endif