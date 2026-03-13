/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:36:01 by mohkhald          #+#    #+#             */
/*   Updated: 2026/03/11 15:36:16 by mohkhald         ###   ########.fr       */
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
