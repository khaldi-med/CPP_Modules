#include <iostream>
#include <cassert>
#include "searchable_tree_bag.hpp"
#include "searchable_arry_bag.hpp"

void test_bag(searchable_bag* bag) {
    bag->insert(10);
    bag->insert(20);
    bag->insert(30);

    assert(bag->has(10) == true);
    assert(bag->has(20) == true);
    assert(bag->has(30) == true);
    assert(bag->has(40) == false);

    bag->clear();
    assert(bag->has(10) == false);

    std::cout << "Test passed!" << std::endl;
}

int main() {
    searchable_tree_bag tree_b;
    std::cout << "Testing tree bag..." << std::endl;
    test_bag(&tree_b);

    searchable_array_bag array_b;
    std::cout << "Testing array bag..." << std::endl;
    test_bag(&array_b);

    return 0;
}
