#ifndef FragTrap_HPP
#define FragTrap_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string name);
	~FragTrap();
	FragTrap(FragTrap const& src);
	FragTrap& operator=(FragTrap const& rhs);

	void highFivesGuys(void); 
private:
	
};

#endif