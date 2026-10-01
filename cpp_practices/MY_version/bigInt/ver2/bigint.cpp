#include "bigint.hpp"
#include <algorithm>
#include <iostream>
#include <string>

BigInt::BigInt() : _digit("0"){};

BigInt::BigInt(const std::string &str) : _digit(str)
{
}

BigInt::BigInt(long long n)
{
	if (n <= 0)
	{
		_digit = "0";
		return ;
	}
	_digit.clear();
	while (n > 0)
	{
		_digit += static_cast<char>(n % 10) + '0';
		n /= 10;
	}
	std::reverse(_digit.begin(), _digit.end());
}

BigInt::BigInt(const BigInt &oth)
{
	_digit = oth._digit;
}

BigInt &BigInt::operator=(const BigInt &oth)
{
	if (this != &oth)
	{
		_digit = oth._digit;
	}
	return (*this);
}

BigInt BigInt::operator+(const BigInt &oth) const
{
	int carry = 0;
	std::string result = "";
	int i = (int)oth._digit.size() - 1;
	int j = (int)_digit.size() - 1;

	while (i >= 0 || j >= 0 || carry > 0)
	{
		int sum = carry;
		if (i >= 0)
		{
			sum += oth._digit[i] - '0';
			i--;
		}
		if (j >= 0)
		{
			sum += _digit[j] - '0';
			j--;
		}
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
	}
	std::reverse(result.begin(), result.end());
	return (BigInt(result));
};

BigInt &BigInt::operator+=(const BigInt &oth)
{
	*this = *this + oth;
	return (*this);
}
BigInt BigInt::operator-(const BigInt &oth)
{
	(void)oth;
	return (BigInt(0));
}

BigInt &BigInt::operator++()
{
	*this += BigInt(1);
	return (*this);
}

BigInt BigInt::operator++(int)
{
	BigInt tmp(*this);
	++(*this);
	return (tmp);
}

BigInt BigInt::operator<<(const BigInt &oth) const
{
	if (_digit == "0")
		return (*this);

	int num_zeros = std::stoi(oth._digit);

	BigInt result(*this);
	result._digit.append(num_zeros, '0');
	return (result);

}

BigInt BigInt::operator>>(const BigInt &oth) const
{
  if (_digit == "0")
    return (*this);

  int num_zeros = std::stoi(oth._digit);
  BigInt result(*this);
  result._digit.erase(0, num_zeros);
  return (result);
}

BigInt::~BigInt()
{
}

std::ostream &operator<<(std::ostream &os, const BigInt &oth)
{
	os << oth._digit;
	return (os);
};
