#ifndef SET_HPP
# define SET_HPP

#include "searchable_bag.hpp"
#include <cstddef>

class set {
	searchable_bag *bag;

public:
	set() : bag(NULL) {}
	set(searchable_bag &b) : bag(&b) {}
	set(const set &other) : bag(other.bag) {}
	set &operator=(const set &other)
	{
		if (this != &other)
			bag = other.bag;
		return *this;
	}
	~set() {}

	void insert(int n)
	{
		if (bag && !bag -> has(n))
			bag -> insert(n);
	}

	void insert(int *array, int size)
	{
		if (array)
		{
			for (int i = 0; i < size; i++)
				insert(array[i]);
		}
	}

	void print() const
	{
		if (bag)
				bag -> print();
	}

	bool has(int n) const
	{
		if (bag)
				return bag -> has(n);
		return false;
	}

	void clear()
	{
		if (bag)
				bag -> clear();
	}

	searchable_bag &get_bag() const
	{
		return *bag;
	}
};

#endif
