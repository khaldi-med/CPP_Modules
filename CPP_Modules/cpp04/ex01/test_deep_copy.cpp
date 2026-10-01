
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

void testDeepCopy() {
    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    Dog* dog1 = new Dog();
    dog1->getBrain()->ideas[0] = "I want a bone";
    
    std::cout << "Dog 1 idea 0: " << dog1->getBrain()->ideas[0] << std::endl;
    
    Dog* dog2 = new Dog(*dog1); // Copy constructor (Deep Copy)
    std::cout << "Dog 2 (copy of Dog 1) idea 0: " << dog2->getBrain()->ideas[0] << std::endl;
    
    std::cout << "Changing Dog 2's idea..." << std::endl;
    dog2->getBrain()->ideas[0] = "I want a ball";
    
    std::cout << "Dog 1 idea 0 (should still be bone): " << dog1->getBrain()->ideas[0] << std::endl;
    std::cout << "Dog 2 idea 0 (should be ball): " << dog2->getBrain()->ideas[0] << std::endl;
    
    delete dog1;
    delete dog2;
}

void testAssignmentOperator() {
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    Cat cat1;
    cat1.getBrain()->ideas[0] = "I want fish";
    
    Cat cat2;
    cat2 = cat1; // Assignment operator (Deep Copy)
    
    std::cout << "Cat 2 idea 0: " << cat2.getBrain()->ideas[0] << std::endl;
    cat2.getBrain()->ideas[0] = "I want milk";
    
    std::cout << "Cat 1 idea 0 (should still be fish): " << cat1.getBrain()->ideas[0] << std::endl;
    std::cout << "Cat 2 idea 0 (should be milk): " << cat2.getBrain()->ideas[0] << std::endl;
}

void testPolymorphism() {
    std::cout << "\n--- Testing Polymorphism ---" << std::endl;
    const Animal* meta[4];
    
    meta[0] = new Dog();
    meta[1] = new Cat();
    meta[2] = new Dog();
    meta[3] = new Cat();
    
    for (int i = 0; i < 4; i++) {
        std::cout << meta[i]->getType() << " says: ";
        meta[i]->makeSound();
    }
    
    for (int i = 0; i < 4; i++) {
        delete meta[i]; // Virtual destructor ensures Brains are deleted
    }
}

int main() {
    testDeepCopy();
    testAssignmentOperator();
    testPolymorphism();
    return 0;
}
