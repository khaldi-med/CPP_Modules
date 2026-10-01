#include "searchable_tree_bag.hpp"
#include "tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {};

searchable_tree_bag::~searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other):tree_bag(other) {};

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other) {
	if (this != &other)
		tree_bag::operator = (other);
	return *this;
}

bool searchable_tree_bag::has(int val) const {
	node *n = this->tree;
	while (n) {
		if (n->value ==val)
			return true;
		if (val < n->value)
			n = n->l;
		else
			n = n->r;
	}
	return false;
}
