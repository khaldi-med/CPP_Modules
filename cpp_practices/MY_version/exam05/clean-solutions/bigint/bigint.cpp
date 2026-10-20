#include "bigint.hpp"

#include <sstream>

std::string bigint::normalize(const std::string &s)
{
	std::string::size_type first = s.find_first_not_of('0');
	return first == std::string::npos ? "0" : s.substr(first);
}

bigint bigint::from_digits(const std::string &s)
{
	bigint result;
	result.value = normalize(s);
	return result;
}

bigint::bigint() : value("0") {}

bigint::bigint(unsigned long n)
{
	std::ostringstream out;
	out << n;
	value = out.str();
}

bigint::bigint(const std::string &s) : value(normalize(s)) {}

bigint bigint::operator+(const bigint &other) const
{
	std::string result;
	int i = static_cast<int>(value.size()) - 1;
	int j = static_cast<int>(other.value.size()) - 1;
	int carry = 0;
	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0) sum += value[i--] - '0';
		if (j >= 0) sum += other.value[j--] - '0';
		result.insert(result.begin(), static_cast<char>('0' + sum % 10));
		carry = sum / 10;
	}
	return from_digits(result);
}

bigint &bigint::operator+=(const bigint &other)
{
	return *this = *this + other;
}

bigint bigint::operator-(const bigint &other) const
{
	if (*this < other) return bigint();
	std::string result = value;
	int i = static_cast<int>(result.size()) - 1;
	int j = static_cast<int>(other.value.size()) - 1;
	int borrow = 0;
	while (i >= 0) {
		int digit = result[i] - '0' - borrow;
		int sub = j >= 0 ? other.value[j--] - '0' : 0;
		if (digit < sub) { digit += 10; borrow = 1; } else borrow = 0;
		result[i--] = static_cast<char>('0' + digit - sub);
	}
	return from_digits(result);
}

bigint &bigint::operator-=(const bigint &other)
{
	return *this = *this - other;
}

bigint bigint::operator<<(unsigned int n) const
{
	return value == "0" ? *this : from_digits(value + std::string(n, '0'));
}

bigint bigint::operator>>(unsigned int n) const
{
	return n >= value.size() ? bigint() : from_digits(value.substr(0, value.size() - n));
}

bigint bigint::operator<<(const bigint &n) const
{
	std::istringstream in(n.value);
	unsigned int shift = 0;
	in >> shift;
	return *this << shift;
}

bigint bigint::operator>>(const bigint &n) const
{
	std::istringstream in(n.value);
	unsigned int shift = 0;
	in >> shift;
	return *this >> shift;
}

bigint &bigint::operator<<=(unsigned int n) { return *this = *this << n; }
bigint &bigint::operator>>=(unsigned int n) { return *this = *this >> n; }
bigint &bigint::operator<<=(const bigint &n) { return *this = *this << n; }
bigint &bigint::operator>>=(const bigint &n) { return *this = *this >> n; }

bigint &bigint::operator++() { return *this += bigint(1); }
bigint bigint::operator++(int) { bigint old(*this); ++*this; return old; }

bool bigint::operator==(const bigint &o) const { return value == o.value; }
bool bigint::operator!=(const bigint &o) const { return !(*this == o); }
bool bigint::operator<(const bigint &o) const
{
	return value.size() != o.value.size() ? value.size() < o.value.size() : value < o.value;
}
bool bigint::operator<=(const bigint &o) const { return !(o < *this); }
bool bigint::operator>(const bigint &o) const { return o < *this; }
bool bigint::operator>=(const bigint &o) const { return !(*this < o); }

std::ostream &operator<<(std::ostream &out, const bigint &n)
{
	return out << n.value;
}
