#include "bigint.hpp"

//default constructor
Bigint::Bigint() : _digit("0") {};

//parametre constructor
Bigint::Bigint(long long n){
  if(n<=0){
    _digit = "0";
    return;
  }
  _digit.clear();
  while(n > 0){
    _digit += static_cast<char>('0' + n % 10);
    n /= 10;
  }
  std::reverse(_digit.begin(), _digit.end());
}

//copy constructor.
Bigint::Bigint(const Bigint &other): _digit(other._digit) {}

//Assignments
Bigint &Bigint::operator=(const Bigint &other){
  if(this != other)
    _digit = other._digit;
  return *this;
}

//Addition
Bigint Bigint::operator+(const Bigint &other) const{
  Bigint result;
   result._digit.clear();
   int carry;

}


