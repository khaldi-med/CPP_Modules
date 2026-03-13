/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:44:59 by mohkhald          #+#    #+#             */
/*   Updated: 2026/03/12 18:04:43 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}

std::string	PhoneBook::_formatCol(std::string const &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

static std::string	readField(std::string const &prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return ("");
		}
		if (!input.empty())
			return (input);
		std::cout << "Field cannot be empty. Try again." << std::endl;
	}
}

void	PhoneBook::addContact()
{
	Contact	c;

	c.setFirstName(readField("First name      : "));
	if (c.getFirstName().empty())
		return ;
	c.setLastName(readField("Last name       : "));
	if (c.getLastName().empty())
		return ;
	c.setNickname(readField("Nickname        : "));
	if (c.getNickname().empty())
		return ;
	c.setPhoneNumber(readField("Phone number    : "));
	if (c.getPhoneNumber().empty())
		return ;
	c.setDarkestSecret(readField("Darkest secret  : "));
	if (c.getDarkestSecret().empty())
		return ;
	_contacts[_oldest] = c;
	_oldest = (_oldest + 1) % 8;
	if (_count < 8)
		_count++;
	std::cout << "Contact added successfully." << std::endl;
}

void	PhoneBook::searchContact() const
{
	if (_count == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return ;
	}
	std::cout << std::right
		<< std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::right
			<< std::setw(10) << i << "|"
			<< std::setw(10) << _formatCol(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << _formatCol(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << _formatCol(_contacts[i].getNickname())
			<< std::endl;
	}
	std::string	input;
	int			idx;
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')	
	{
    	std::cout << "Invalid index." << std::endl;
    	return;
	}
	idx = input[0] - '0';
	if (idx >= _count)
	{
    	std::cout << "Index out of range." << std::endl;
    	return;
	}
	std::cout << "First name     : " << _contacts[idx].getFirstName() << std::endl;
	std::cout << "Last name      : " << _contacts[idx].getLastName() << std::endl;
	std::cout << "Nickname       : " << _contacts[idx].getNickname() << std::endl;
	std::cout << "Phone number   : " << _contacts[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << _contacts[idx].getDarkestSecret() << std::endl;
}
