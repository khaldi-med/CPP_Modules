/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 05:12:44 by mohkhald          #+#    #+#             */
/*   Updated: 2026/04/08 08:58:13 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int count = 4;
	Animal* animals[count];

	for (int i = 0; i < count / 2; i++) {
		animals[i] = new Dog();
	}
	for (int i = count / 2; i < count; i++) {
		animals[i] = new Cat();
	}
  
  for (int i = 0; i < count; i++) {
    animals[i]->makeSound();
  }
  
	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "Tmp dog brain: " << tmp.getBrain() << std::endl;
		std::cout << "Basic dog brain: " << basic.getBrain() << std::endl;
	}
  Dog dog;
  dog.getBrain()->ideas[0] = "I want a bone";
  
  std::cout << "Dog idea 0: " << dog.getBrain()->ideas[0] << std::endl;
  Dog dog2 = dog;
  
  std::cout << "Dog 2 idea 0: " << dog2.getBrain()->ideas[0] << std::endl;
  
  std::cout << "Changing Dog 2's idea..." << std::endl;
  dog2.getBrain()->ideas[0] = "I want a ball";
  
  std::cout << "Dog 1 idea 0 (should still be bone): " << dog.getBrain()->ideas[0] << std::endl;
  std::cout << "Dog 2 idea 0 (should be ball): " << dog2.getBrain()->ideas[0] << std::endl;

  Cat cat;
  cat.getBrain()->ideas[0] = "I want a fish";
  
  std::cout << "Cat idea 0: " << cat.getBrain()->ideas[0] << std::endl;

  for (int i = 0; i < count; i++) {
		delete animals[i];
	}

	return 0;
}
