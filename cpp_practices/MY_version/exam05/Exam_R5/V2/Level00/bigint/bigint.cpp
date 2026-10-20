#include "bigint.hpp"

std::ostream &operator<<(std::ostream &os, const bigint &bn)
{
	os << bn.getNum();
	return os;
}