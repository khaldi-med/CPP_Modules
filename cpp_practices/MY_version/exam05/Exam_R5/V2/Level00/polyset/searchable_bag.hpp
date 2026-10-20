#pragma once

#include "bag.hpp"

class searchable_bag : virtual public bag {
public:
    virtual ~searchable_bag() {}
    virtual bool has(int) const = 0;
};

#include "searchable_array_bag.hpp" // added
#include "searchable_tree_bag.hpp" // added
#include "set.hpp"  // added


