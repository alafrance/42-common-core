/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:03:36 by alafranc          #+#    #+#             */
/*   Updated: 2021/09/09 14:21:57 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	Zombie *zombie = newZombie("John");

	randomChump("Smith");
	zombie->announce();
	delete zombie;
}