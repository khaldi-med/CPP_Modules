#include "searchable_arry_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"
#include <iostream>

int	main(void)
{
	searchable_array_bag	a;
	searchable_array_bag	b;
	searchable_array_bag	c;
	searchable_tree_bag		t;
	searchable_tree_bag		t2;
	searchable_tree_bag		t3;

	// ---- test searchable_array_bag ----
	std::cout << "=== searchable_array_bag ===" << std::endl;
	a.insert(5);
	a.insert(3);
	a.insert(7);
	a.insert(2);
	std::cout << "contents: ";
	a.print(); // 5 3 7 2
	std::cout << "has 3? " << a.has(3) << std::endl;   // 1 (true)
	std::cout << "has 99? " << a.has(99) << std::endl; // 0 (false)
	// test copy constructor
	b = a;
	std::cout << "copy of a: ";
	b.print(); // 5 3 7 2
	// test assignment operator
	c = a;
	std::cout << "assigned from a: ";
	c.print(); // 5 3 7 2
	// test independence — clearing a should not affect b or c
	a.clear();
	std::cout << "after clearing a:" << std::endl;
	std::cout << "b still has 3? " << b.has(3) << std::endl; // 1 (true)
	std::cout << "c still has 3? " << c.has(3) << std::endl; // 1 (true)
	// ---- test searchable_tree_bag ----
	std::cout << "\n=== searchable_tree_bag ===" << std::endl;
	t.insert(5);
	t.insert(3);
	t.insert(7);
	t.insert(2);
	std::cout << "contents (sorted): ";
	t.print(); // 2 3 5 7 (BST prints sorted)
	std::cout << "has 7? " << t.has(7) << std::endl;   // 1 (true)
	std::cout << "has 99? " << t.has(99) << std::endl; // 0 (false)
	// test copy constructor
	t2 = t;
	std::cout << "copy of t: ";
	t2.print(); // 2 3 5 7
	// test assignment operator
	t3 = t;
	std::cout << "assigned from t: ";
	t3.print(); // 2 3 5 7
	// test independence
	t.clear();
	std::cout << "after clearing t:" << std::endl;
	std::cout << "t2 still has 7? " << t2.has(7) << std::endl; // 1 (true)
	std::cout << "t3 still has 7? " << t3.has(7) << std::endl; // 1 (true)
                                                             // ---- test set ----
	set sa(*a); // constructor — takes a searchable_bag reference
	set st(*t); // same
	st.insert(val); // insert — but no duplicates allowed
	sa.insert(val);
	sa.has(val);          // search — forward to internal bag
	sa.print();           // print — forward to internal bag
	sa.get_bag().print(); // get_bag() — return the internal bag
	st.print();
	sa.clear(); // clear — forward to internal bag
	sa.insert((int[]){1, 2, 3, 4}, 4); // insert array version
	return (0);
}
