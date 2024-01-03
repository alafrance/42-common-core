#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap playerA("Gotaga");
	ClapTrap playerB("Gataga");
	ClapTrap playerC(playerA);
	ScavTrap playerD("Gitigi");
	FragTrap playerE("Gytygy");

	playerC.setAttackDamage(20);
	playerC.setName("Gutugu");
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttackDamage());
	playerC.attack(playerA.getName());
	playerA.takeDamage(playerC.getAttackDamage());
	playerC.beRepaired(20);
	playerD.attack(playerA.getName());
	playerD.guardGate();
	playerE.highFivesGuys();
}
