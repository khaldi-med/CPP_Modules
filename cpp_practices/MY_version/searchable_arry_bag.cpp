#include "searchable_arry_bag.hpp"
#include "array_bag.hpp"

searchable_array_bag::searchable_array_bag(): array_bag() {
}

searchable_array_bag::~searchable_array_bag() {
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other): array_bag(other) {

}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other) {
	if (this != &other) {
		array_bag::operator = (other);
	}
	return *this;
}


bool searchable_array_bag:: has(int val) const {
	for (int i = 0; i < this->size; i++) {
		if (this->data[i] == val)
			return true;
	}
	return false;
}
