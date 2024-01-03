#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap playerA("Gotaga");
	ClapTrap playerB("Gataga");

	playerB.setAttackDamage(20);
	playerB.setName("Gutugu");
	playerB.attack(playerA.getName());
	playerA.takeDamage(playerB.getAttackDamage());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttackDamage());
	playerA.beRepaired(20);
	playerA.guardGate();
}
