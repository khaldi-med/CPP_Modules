/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:43:57 by mohkhald          #+#    #+#             */
/*   Updated: 2026/04/01 21:43:57 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int hordeSize = 5;
	
	Zombie* horde = zombieHorde(hordeSize, "HordeZombie");

	if (horde) {
		for (int i = 0; i < hordeSize; i++) {
			std::cout << "Zombie " << i << ": ";
			horde[i].announce();
		}
		delete[] horde;
	}

	return 0;
}
