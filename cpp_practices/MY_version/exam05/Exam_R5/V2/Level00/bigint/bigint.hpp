#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint {
	std::string num;

	public:
	bigint() : num("0") {}

	bigint(unsigned long n)
	{
		std::stringstream ss;
		ss << n;
		num = ss.str();
	}

	bigint(const std::string &s)
	{
		size_t pos = s.find_first_not_of('0');
		if (pos != std::string::npos)
			num = s.substr(pos);
		else
			num = "0";
	}

	bigint(const bigint &oth) : num(oth.num) {}

	bigint &operator=(const bigint &oth)
	{
		if (this != &oth)
			num = oth.num;
		return *this;
	}

	~bigint() {}

	bigint operator+(const bigint &oth) const
	{
		int i = num.length() - 1;
		int j = oth.num.length() - 1;
		int carry = 0;
		std::string res = "";
		while (i >= 0 || j >= 0 || carry)
		{
			int dig1 = (i >= 0) ? num[i] - '0' : 0;
			int dig2 = (j >= 0) ? oth.num[j] - '0' : 0;
			int sum = dig1 + dig2 + carry;
			char c = sum % 10 + '0';
			carry = sum / 10;
			res.insert(res.begin(), c);
			i--; j--;
		}
		return bigint(res);
	}

	bigint &operator+=(const bigint &oth)
	{
		*this = *this + oth;
		return *this;
	}

	bool operator==(const bigint &oth) const
	{
		return num == oth.num;
	}

	bool operator!=(const bigint &oth) const
	{
		return num != oth.num;
	}

	bool operator<(const bigint &oth) const
	{
		if (num.size() != oth.num.size())
			return num.size() < oth.num.size();
		return num < oth.num;
	}

	bool operator<=(const bigint &oth) const
	{
		if (num.size() != oth.num.size())
			return num.size() <= oth.num.size();
		return num <= oth.num;
	}

	bool operator>(const bigint &oth) const
	{
		if (num.size() != oth.num.size())
			return num.size() > oth.num.size();
		return num > oth.num;
	}

	bool operator>=(const bigint &oth) const
	{
		if (num.size() != oth.num.size())
			return num.size() >= oth.num.size();
		return num >= oth.num;
	}

	bigint operator<<(unsigned int n) const
	{
		if (num == "0")
			return *this;
		return bigint(num + std::string(n, '0'));
	}

	bigint operator>>(unsigned int n) const
	{
		if (n >= num.size())
			return bigint("0");
		return bigint(num.substr(0, num.size() - n));
	}

	bigint operator<<(const bigint &oth) const
	{
		unsigned int n = 0;
		std::stringstream ss;
		ss << oth.num;
		ss >> n;
		return *this << n;
	}

	bigint operator>>(const bigint &oth) const
	{
		unsigned int n = 0;
		std::stringstream ss;
		ss << oth.num;
		ss >> n;
		return *this >> n;
	}

	bigint &operator<<=(unsigned int n)
	{
		*this = *this << n;
		return *this;
	}

	bigint &operator<<=(const bigint &oth)
	{
		*this = *this << oth;
		return *this;
	}

	bigint &operator>>=(unsigned int n)
	{
		*this = *this >> n;
		return *this;
	}

	bigint &operator>>=(const bigint &oth)
	{
		*this = *this >> oth;
		return *this;
	}

	bigint &operator++()
	{
		*this += 1;
		return *this;
	}

	bigint operator++(int)
	{
		bigint tmp = *this;
		*this += 1;
		return tmp;
	}

	const std::string &getNum() const
	{
		return num;
	}
};

std::ostream &operator<<(std::ostream &os, const bigint &bn);

#endif
