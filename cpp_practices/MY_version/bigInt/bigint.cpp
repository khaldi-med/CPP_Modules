#include "bigint.hpp"

//default constructor
Bigint::Bigint() : _digit("0") {};

//parametre constructor
Bigint::Bigint(long long n) {
	if (n<=0) {
		_digit = "0";
		return;
	}
	_digit.clear();
	while (n > 0) {
		_digit += static_cast<char>('0' + n % 10);
		n /= 10;
	}
	std::reverse(_digit.begin(), _digit.end());
}

//copy constructor.
Bigint::Bigint(const Bigint &other): _digit(other._digit) {}

//Assignments
Bigint operator+(const Bigint &other)  {
  Bigint result;
  int i = _digit.size() - 1;
  int j = other._digit.size() - 1;
  int carry = 0;
 
  return result;
}                             
              
std::ostream &operator<<(std::ostream &os, const Bigint &n) {
	os << n._digit;
	return os;
}                             
