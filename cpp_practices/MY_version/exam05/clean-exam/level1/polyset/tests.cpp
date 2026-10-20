#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"
#include <cassert>
static void check(searchable_bag &b)
{
	int values[] = {4, 2, 4, -1};
	b.insert(values, 4);
	assert(b.has(4) && b.has(-1) && !b.has(3));
	searchable_bag *copy = dynamic_cast<searchable_bag *>(&b);
	assert(copy);
	b.clear(); assert(!b.has(4));
}
int main()
{
	searchable_array_bag a; searchable_tree_bag t;
	check(a); check(t);
	set s(a); int values[] = {1, 1, 2, 3}; s.insert(values, 4);
	assert(s.has(1) && s.has(3) && !s.has(4));
	s.clear(); assert(!s.has(1));
	return 0;
}
