/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaouar <mohaouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:36:42 by mohaouar          #+#    #+#             */
/*   Updated: 2026/04/01 20:27:35 by mohaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Constructing ---" << std::endl;
    FragTrap f1("Claptrap-Unit-High-Five");

    std::cout << "\n--- Testing Actions ---" << std::endl;
    
    f1.attack("Handsome Jack"); 
    f1.takeDamage(10); 
    f1.beRepaired(10); 
    f1.highFivesGuys();

    std::cout << "\n--- Destructing ---" << std::endl;
    return 0;
}