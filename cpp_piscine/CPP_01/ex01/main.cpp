/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:23:28 by alafranc          #+#    #+#             */
/*   Updated: 2021/09/21 10:42:31 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {
	int N = 5;
	Zombie *allZombie = zombieHorde(N, "Kevin");

	for (int i = 0; i < N; i++)
		allZombie[i].announce();
	delete[] allZombie;
}