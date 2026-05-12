#include "bigint.hpp"
#include <iostream>

int main() {

	Bigint a(42);
	Bigint b;
	Bigint c;
	Bigint d(b);
  
  b = a;

  c = a + b;
	std::cout<< "a = " << a << std::endl;
	std::cout<< "b = " << b << std::endl;
	std::cout<< "c = " << c << std::endl;
	std::cout<< "d = " << d << std::endl;
}
