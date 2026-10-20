#include "set.hpp"

set::set(searchable_bag &oth) : bag(oth) {}

set::~set() {
    bag.clear();
}

void set::insert(int val) {
    if (!bag.has(val)) {
        bag.insert(val);
    }
}

void set::insert(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        insert(arr[i]);
    }
}

bool set::has(int val) const {
    return bag.has(val);
}

void set::print() const {
    bag.print();
}

searchable_bag &set::get_bag() const {
    return bag;
}

void set::clear() {
    bag.clear();
}
