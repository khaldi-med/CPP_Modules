#ifndef SET_HPP
#define SET_HPP
#include "searchable_bag.hpp"
class set {
	searchable_bag *bag;
public:
	set() : bag(0) {}
	set(searchable_bag &b) : bag(&b) {}
	set(const set &o) : bag(o.bag) {}
	set &operator=(const set &o) { if (this != &o) bag = o.bag; return *this; }
	void insert(int n) { if (bag && !bag->has(n)) bag->insert(n); }
	void insert(int *a, int n) { for (int i = 0; a && i < n; ++i) insert(a[i]); }
	bool has(int n) const { return bag && bag->has(n); }
	void print() const { if (bag) bag->print(); }
	void clear() { if (bag) bag->clear(); }
	searchable_bag &get_bag() const { return *bag; }
};
#endif
