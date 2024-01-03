#pragma once
#ifndef ZOMBIE
#define ZOMBIE
#include <iostream>

class Zombie
{
public:
	Zombie(const std::string& name);
	Zombie();
	~Zombie();
	void		announce();
	const std::string	getName();
	void		setName(const std::string& name);
private:
	std::string _name;
};
#endif // ZOMBIE