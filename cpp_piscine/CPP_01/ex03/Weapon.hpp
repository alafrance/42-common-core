#pragma once
#ifndef WEAPON
#define WEAPON
#include <iostream>

class Weapon
{
public:
    Weapon(std::string p_type);
    ~Weapon();
    std::string const getType();
    void    setType(std::string p_type);
private:
    std::string _type;
};

#endif