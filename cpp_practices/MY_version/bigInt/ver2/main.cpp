#include "bigint.hpp"
#include <iostream>

int main()
{
	 BigInt a(18); 
	 BigInt b(10); 
   BigInt c = a + b;
 
 // std::cout << "(c <<= 10) = " << (c <<= 10) << std::endl;
 std::cout << "a = " << a << std::endl;
 std::cout << "b = " << b << std::endl;
 std::cout << "c = " << c << std::endl;
 // std::cout << "d = " << d << std::endl;
 // std::cout << "e = " << e << std::endl;
 std::cout << "a + b = " << a + b << std::endl;
 std::cout << "a - b = " << a - b << std::endl;
 std::cout << "(b += a) = " << (b += a) << std::endl;
 std::cout << "++b = " << ++b << std::endl;
 std::cout << "b++ = " << b++ << std::endl;
 std::cout << "(b << 10) = " << (b << 10) << std::endl;
	// std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
	// std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;
	// std::cout << "(d < a) = " << (d < a) << std::endl;
	// std::cout << "(d > a) = " << (d > a) << std::endl;
	// std::cout << "(d == a) = " << (d == a) << std::endl;
	// std::cout << "(d != a) = " << (d != a) << std::endl;
	// std::cout << "(d <= a) = " << (d <= a) << std::endl;
	// std::cout << "(d >= a) = " << (d >= a) << std::endl;
}
