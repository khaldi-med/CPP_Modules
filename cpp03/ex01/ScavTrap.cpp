/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaouar <mohaouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:40:28 by mohaouar          #+#    #+#             */
/*   Updated: 2026/04/08 02:28:38 by mohaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor Called for " << _name <<std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called." << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy Constructor Called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap Copy Assignment Operator Called." << std::endl;
	
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parameterized Constructor Called." << _name <<std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else 
		std::cout << "ScavTrap " << this->_name << " can't do anything." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now on Gate Keeper mode!" << std::endl;
}