/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaouar <mohaouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:36:42 by mohaouar          #+#    #+#             */
/*   Updated: 2026/04/01 17:39:42 by mohaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "--- Constructing ---" << std::endl;
    ScavTrap s1("Serena");
	
	std::cout << "\n--- Testing Actions ---" << std::endl;
    s1.attack("Handsome Jack");
	
	s1.takeDamage(10);
	s1.beRepaired(10);
	s1.guardGate();
	
	std::cout << "\n--- Destructing ---" << std::endl;
    return 0;
}