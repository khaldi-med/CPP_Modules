#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"
#include <iostream>
#include <cassert>

void test_strict() {
    searchable_array_bag a;
    set s(a);

    // 1. Duplicate Rejection
    s.insert(10);
    s.insert(10); // Should be ignored
    assert(s.has(10) == true);
    
    // 2. Multi-insertion
    int arr[] = {1, 2, 3, 3, 2, 1};
    s.insert(arr, 6);
    // Set should have: 1, 2, 3, 10
    
    assert(s.has(1) == true);
    assert(s.has(2) == true);
    assert(s.has(3) == true);
    assert(s.has(10) == true);
    assert(s.has(99) == false);

    // 3. Clear and Re-use
    s.clear();
    assert(s.has(1) == false);
    
    std::cout << "Array-based strict tests passed successfully!" << std::endl;

    searchable_tree_bag t;
    set s2(t);

    s2.insert(10);
    s2.insert(10);
    assert(s2.has(10) == true);
    
    s2.insert(arr, 6);
    assert(s2.has(1) == true);
    assert(s2.has(2) == true);
    assert(s2.has(3) == true);
    assert(s2.has(10) == true);
    assert(s2.has(99) == false);

    s2.clear();
    assert(s2.has(1) == false);

    std::cout << "Tree-based strict tests passed successfully!" << std::endl;
}

int main() {
    test_strict();
    return 0;
}
