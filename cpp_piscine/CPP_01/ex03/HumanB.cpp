#include "HumanB.hpp"
#include <iostream>
HumanB::HumanB(std::string name, Weapon &weapon){
    *_weapon = weapon;
    _name = name;
}

HumanB::HumanB(std::string name): _weapon(NULL), _name(name){

}


HumanB::~HumanB() {

}

void	HumanB::attack() {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

const std::string HumanB::getName() {
    return _name;
}

void        HumanB::setName(std::string name) {
    _name = name;
}

const Weapon      *HumanB::getWeapon() {
    return _weapon;
}

void        HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}