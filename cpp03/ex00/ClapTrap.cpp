/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaouar <mohaouar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:37:01 by mohaouar          #+#    #+#             */
/*   Updated: 2026/04/08 02:11:45 by mohaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default Constructor Called for " << _name <<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called For " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy Constructor is Called." << std::endl;
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy Assignement Operator Called." << std::endl;
	
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	this->_name = name;
	std::cout << "Parameterized Constructor Called for " << _name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else 
		std::cout << "ClapTrap " << this->_name << " can't do anything." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= (int)amount)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _name << " Repaired itslef!" << std::endl;
		_energy_points--;
		_hit_points += amount;
	}
	else
		std::cout << "ClapTrap " << _name << " Can't Repair itself!" << std::endl;
}