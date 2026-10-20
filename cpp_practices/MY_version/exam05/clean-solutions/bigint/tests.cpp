#include "bigint.hpp"
#include <cassert>
#include <sstream>

static std::string text(const bigint &n)
{
	std::ostringstream out;
	return (out << n).str();
}

int main()
{
	assert(text(bigint()) == "0");
	assert(text(bigint("00000120")) == "120");
	assert(text(bigint("0000")) == "0");
	assert(text(bigint("999999999999999999") + bigint("1")) == "1000000000000000000");
	assert(text(bigint("1000") - bigint("1")) == "999");
	assert(text(bigint("1") - bigint("2")) == "0");
	assert(text(bigint("123") << 4) == "1230000");
	assert(text(bigint("123") >> 2) == "1");
	assert(text(bigint("123") >> 3) == "0");
	assert(text(bigint("0") << 100) == "0");
	assert(text(bigint("12") << bigint("2")) == "1200");
	assert(bigint("9") < bigint("10"));
	assert(bigint("010") == bigint("10"));
	bigint n("999");
	assert(text(n++) == "999" && text(n) == "1000");
	assert(text(++n) == "1001");
	n <<= 2;
	n >>= 1;
	assert(text(n) == "100100");
	return 0;
}
