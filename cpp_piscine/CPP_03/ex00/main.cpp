#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap playerA("Gotaga");
	ClapTrap playerB(playerA);

	playerA.setAttackDamage(20);
	playerB.setName("Gutugu");
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttackDamage());
	playerA.beRepaired(20);
}
