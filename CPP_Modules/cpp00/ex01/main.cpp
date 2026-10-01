/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/03/09 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
  PhoneBook phoneBook;
  std::string cmd;

  while (true) {
    std::cout << "Command (ADD, SEARCH, EXIT): ";
    if (!std::getline(std::cin, cmd))
      break;
    if (cmd == "ADD")
      phoneBook.addContact();
    else if (cmd == "SEARCH")
      phoneBook.searchContact();
    else if (cmd == "EXIT")
      break;
    else
      continue;
  }
  return (0);
}
