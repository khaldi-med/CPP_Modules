/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:22:43 by mohkhald          #+#    #+#             */
/*   Updated: 2026/03/13 22:37:56 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(std::string name) {
  _name = name;
  return;
}

Zombie::~Zombie(void) {
  std::cout << _name << " is dead" << std::endl;
  return;
}

void Zombie::announce(void) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
  return;
}
