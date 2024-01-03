#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap playerA("Gotaga");
	ClapTrap	playerB("Squeezos");
	DiamondTrap	playerC;

	playerA.whoAmI();
	playerA.attack(playerB.getName());
	playerA.guardGate();
	playerA.highFivesGuys();
	playerA.setName("Gataga");
	playerA.takeDamage(playerA.getAttackDamage());
	playerB.attack(playerA.getName());
	playerA.takeDamage(playerB.getAttackDamage());
	playerA.beRepaired(20);
}
