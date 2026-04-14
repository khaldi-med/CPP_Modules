/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaouar <mohaouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:36:42 by mohaouar          #+#    #+#             */
/*   Updated: 2026/04/01 12:20:28 by mohaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "--- Constructing ---" << std::endl;
	
	ClapTrap a;
	ClapTrap b("Bender");
	ClapTrap c(b);
	
	std::cout << "\n--- Testing Actions ---" << std::endl;
	b.attack("Fry");
	b.takeDamage(5);
	b.beRepaired(3);
	
	b.attack("Fry");
	b.attack("Fry");
	b.attack("Fry");
	b.attack("Fry");
	b.attack("Fry");
	b.attack("Fry");
	b.attack("Fry");
	b.attack("Fry");
	b.attack("Fry");
	
	b.attack("Fry");
	b.beRepaired(10);
	
	c.takeDamage(20);
	c.attack("Leela");
	
	std::cout << "\n--- Destructing ---" << std::endl;
	return (0);
}