#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data original;
    original.number = 42;
    original.text = "serialization works";

    Data* originalPointer = &original;
    uintptr_t raw = Serializer::serialize(originalPointer);
    Data* restoredPointer = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << originalPointer << std::endl;
    std::cout << "Raw value: " << raw << std::endl;
    std::cout << "Restored pointer: " << restoredPointer << std::endl;
    std::cout << "Same pointer: "
              << (originalPointer == restoredPointer ? "yes" : "no")
              << std::endl;
    std::cout << "Restored data: " << restoredPointer->number << ", "
              << restoredPointer->text << std::endl;

    return originalPointer == restoredPointer ? 0 : 1;
}
