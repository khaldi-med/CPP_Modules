/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:45:59 by mohkhald          #+#    #+#             */
/*   Updated: 2026/03/12 18:05:58 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>


class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_count;
	int		_oldest;

	std::string	_formatCol(std::string const &str) const;

public:
	PhoneBook();

	void	addContact();
	void	searchContact() const;
};

#endif
