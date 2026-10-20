#include "array_bag.hpp"
#include <iostream>
array_bag::array_bag() : data(0), size(0) {}
array_bag::array_bag(const array_bag &o) : data(0), size(0) { *this = o; }
array_bag &array_bag::operator=(const array_bag &o)
{
	if (this != &o) {
		int *copy = o.size ? new int[o.size] : 0;
		for (int i = 0; i < o.size; ++i) copy[i] = o.data[i];
		delete[] data; data = copy; size = o.size;
	}
	return *this;
}
array_bag::~array_bag() { delete[] data; }
void array_bag::insert(int n) { insert(&n, 1); }
void array_bag::insert(int *a, int n)
{
	if (!a || n <= 0) return;
	int *copy = new int[size + n];
	for (int i = 0; i < size; ++i) copy[i] = data[i];
	for (int i = 0; i < n; ++i) copy[size + i] = a[i];
	delete[] data; data = copy; size += n;
}
void array_bag::print() const
{
	for (int i = 0; i < size; ++i) std::cout << data[i] << (i + 1 == size ? '\n' : ' ');
	if (!size) std::cout << '\n';
}
void array_bag::clear() { delete[] data; data = 0; size = 0; }
