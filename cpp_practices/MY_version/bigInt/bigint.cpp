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
Bigint &Bigint::operator=(const Bigint &other){
  if(this != &other)
    _digit = other._digit;
  return *this;
}

// Addition
Bigint Bigint::operator+(const Bigint &other)  {
  Bigint result;
  
  result._digit.clear();

  int i = static_cast<int>(_digit.size()) - 1;
  int j = static_cast<int>(other._digit.size()) - 1;
  int carry = 0;
  
  while(i >= 0 || j >= 0 || carry){
    int sum = carry;
    if(i >= 0) sum += _digit[i--] - '0';
    if(j >= 0) sum += other._digit[j--] - '0';
  
    carry = sum / 10;
    result._digit += static_cast<char>('0' + sum % 10);
  }
  if(result._digit.empty())
    result._digit = "0";

  std::reverse(result._digit.begin(), result._digit.end());

  return result;
}

//Pre-increment
Bigint Bigint::operator++(int n){
  *this += Bigint(1);
  return *this;
}

//Post-increment
Bigint Bigint::operator++(){
  Bigint tmp(*this);
  ++(*this);
  return tmp;
}

//dicrement
Bigint Bigint::operator-(const Bigint &other) {
  return Bigint(0);
}

Bigint &Bigint::operator+=(const Bigint &other){
  *this += *this + other;
  return *this;
}

Bigint Bigint::operator<<(const Bigint &other){
  return *this << other;
}


std::ostream &operator<<(std::ostream &os, const Bigint &n) {
	os << n._digit;
	return os;
}
