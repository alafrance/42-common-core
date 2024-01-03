#ifndef HUMANB
#define HUMANB
#include "Weapon.hpp"
#include <iostream>
class HumanB
{
public:
    HumanB(std::string name, Weapon &weapon);
    HumanB(std::string name);
    ~HumanB();
    void        attack();
    const std::string getName();
    void        setName(std::string name);
    const Weapon      *getWeapon();
    void        setWeapon(Weapon &weapon);
private:
    Weapon *_weapon;
    std::string _name;
};

#endif