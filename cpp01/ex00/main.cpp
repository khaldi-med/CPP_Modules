/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:23:37 by mohkhald          #+#    #+#             */
/*   Updated: 2026/03/13 23:04:29 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    std::string name;
  std::cout << "Enter a name:";
  std::getline(std::cin, name);
  Zombie zombie1(name);
  zombie1.announce();
  return 0;
}
