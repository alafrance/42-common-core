#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name): _name(name) {
}

Zombie::~Zombie() {
	std::cout << "Destructor of " << _name << " called" << std::endl;
}

void    Zombie::announce() {
	std::cout << _name << " BraiiiiiiinnnzzzZ" << std::endl;
}

const std::string Zombie::getName() {
	return _name;
}

void		Zombie::setName(const std::string& name) {
	_name = name;
}
