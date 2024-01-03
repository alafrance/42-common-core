#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& src);
	~ClapTrap();
	ClapTrap& operator=(ClapTrap const& rhs);
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	/* ACCESSORS */
	std::string getName() const;
	void		setName(std::string name);
	int			getHitpoints() const;
	void		setHitpoints(int hp);
	int			getEnergyPoints() const;
	void		setEnergyPoints(int energyPoint);
	int			getAttackDamage() const;
	void		setAttackDamage(int AttackDamage);
protected:
	std::string	_name;
	int			_hitpoints;
	int			_energyPoint;
	int 		_attackDamage;

};

#endif