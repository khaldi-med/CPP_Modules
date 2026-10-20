#pragma once

#include "searchable_bag.hpp"

class set {
private:
    searchable_bag &bag;

public:
    set(searchable_bag &oth);
    ~set();

    void insert(int val);
    void insert(int *arr, int size);
    bool has(int val) const;
    void print() const;
    searchable_bag &get_bag() const;
    void clear();
};
