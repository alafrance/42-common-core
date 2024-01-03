#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string p_type): _type(p_type) {

}

Weapon::~Weapon() {

}

std::string const Weapon::getType() {
    return _type;
}

void   Weapon::setType(std::string p_type) {
    _type = p_type;
}