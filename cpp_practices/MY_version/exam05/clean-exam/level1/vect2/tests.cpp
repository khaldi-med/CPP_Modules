#include "vect2.hpp"
#include <cassert>
#include <sstream>
int main()
{
	vect2 a, b(2, 3);
	assert(a == vect2(0, 0));
	assert(b + vect2(1, -3) == vect2(3, 0));
	assert(b - 2 == vect2(0, 1));
	assert(2 + b == vect2(4, 5));
	assert(2 - b == vect2(0, -1));
	assert(3 * b == vect2(6, 9));
	a = b; a += 2; a *= -2; assert(a == vect2(-8, -10));
	assert(b[0] == 2 && b[1] == 3);
	assert((++b) == vect2(3, 4) && b-- == vect2(3, 4));
	std::ostringstream out; out << b; assert(out.str() == "{2, 3}");
	return 0;
}
