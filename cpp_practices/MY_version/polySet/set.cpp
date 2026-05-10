#include "searchable_bag.hpp"
#include "set.hpp"

set::set(searchable_bag &bag) : bag(bag) {};

set::~set() {};

set &set::operator=(const set &other)
{
	(void)other;
	return (*this);
};

set::set(const set &other) : bag(other.bag) {};

void set::insert(int val)
{
	if (!bag.has(val))
		;
	bag.insert(val);
};

void set::insert(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		this->insert(arr[i]);
};

void set::clear()
{
	bag.clear();
};

bool set::has(int val) const
{
	return bag.has(val);
}

void set::print() const
{
	bag.print();
};

searchable_bag &set::get_bag() const
{
	return (bag);
};
