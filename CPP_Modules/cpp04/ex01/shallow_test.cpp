
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class ShallowDog : public Animal {
private:
    Brain* brain;

public:
    ShallowDog() : Animal() {
        type = "ShallowDog";
        brain = new Brain();
        std::cout << "ShallowDog constructor" << std::endl;
    }

    // SHALLOW COPY CONSTRUCTOR (The mistake)
    ShallowDog(const ShallowDog& other) : Animal(other) {
        std::cout << "ShallowDog COPY constructor (SHALLOW!)" << std::endl;
        this->brain = other.brain; // Just copying the pointer!
    }

    ~ShallowDog() {
        delete brain;
        std::cout << "ShallowDog destructor" << std::endl;
    }

    Brain* getBrain() const { return brain; }
};

int main() {
    std::cout << "--- Creating Dog A ---" << std::endl;
    ShallowDog* dogA = new ShallowDog();
    dogA->getBrain()->ideas[0] = "Original Idea";

    std::cout << "\n--- Creating Dog B (Copy of A) ---" << std::endl;
    ShallowDog* dogB = new ShallowDog(*dogA);

    std::cout << "\nChecking ideas..." << std::endl;
    std::cout << "Dog A Idea: " << dogA->getBrain()->ideas[0] << std::endl;
    std::cout << "Dog B Idea: " << dogB->getBrain()->ideas[0] << std::endl;

    std::cout << "\n--- Modifying Dog B's Idea ---" << std::endl;
    dogB->getBrain()->ideas[0] = "CHANGED Idea";

    std::cout << "Dog A Idea (OOPS!): " << dogA->getBrain()->ideas[0] << std::endl;
    std::cout << "Dog B Idea: " << dogB->getBrain()->ideas[0] << std::endl;

    std::cout << "\n--- Deleting Dog A ---" << std::endl;
    delete dogA; 

    std::cout << "\n--- Accessing Dog B's Brain after A is deleted ---" << std::endl;
    // CRASH WARNING: dogB's brain was deleted when dogA was deleted!
    // std::cout << dogB->getBrain()->ideas[0] << std::endl; 

    std::cout << "\n--- Deleting Dog B (This will cause a DOUBLE FREE error) ---" << std::endl;
    // delete dogB; // UNCOMMENT THIS TO SEE THE CRASH

    return 0;
}
