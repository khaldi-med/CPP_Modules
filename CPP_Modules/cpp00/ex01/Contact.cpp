/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/03/09 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string const &firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(std::string const &lastName)
{
	_lastName = lastName;
}

void	Contact::setNickname(std::string const &nickname)
{
	_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string const &phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string const &darkestSecret)
{
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName() const
{
	return (_firstName);
}

std::string	Contact::getLastName() const
{
	return (_lastName);
}

std::string	Contact::getNickname() const
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

bool	Contact::isEmpty() const
{
	return (_firstName.empty());
}
