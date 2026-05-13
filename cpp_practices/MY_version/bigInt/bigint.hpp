#include <iostream>
#include <ostream>
#include <string>

class Bigint
{
	std::string _digit;

public:

	Bigint();
	Bigint(long long n);
	Bigint(const Bigint &other);

  //Assignments
  Bigint &operator=(const Bigint &other);
  
  //Arithmetic
  Bigint operator+(const Bigint &other);
  Bigint &operator+=(const Bigint &other);
  Bigint operator-(const Bigint &other);
  // Bigint &operator-=(const Bigint &other);

  //Comparisons
  Bigint operator==(const Bigint &other) const;
  Bigint operator!=(const Bigint &other) const;
  Bigint operator>=(const Bigint &other) const;
  Bigint operator<=(const Bigint &other) const;
  Bigint operator<(const Bigint &other) const;
  Bigint operator>(const Bigint &other) const;

  //Increment/Decrement
  Bigint operator++();
  Bigint operator++(int);
  // Bigint &operator--();
  // Bigint operator--(int);

  //bit-shifts
  Bigint operator<<(const Bigint &other);
  Bigint &operator<<=(const Bigint &other);
  Bigint operator>>(const Bigint &other);
  Bigint &operator>>=(const Bigint &other);

  //I/O
friend std::ostream &operator<<(std::ostream &os, const Bigint &n);
};
