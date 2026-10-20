#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
	std::string value;
	static std::string normalize(const std::string &);
	static bigint from_digits(const std::string &);
	friend std::ostream &operator<<(std::ostream &, const bigint &);

public:
	bigint();
	bigint(unsigned long);
	bigint(const std::string &);

	bigint operator+(const bigint &) const;
	bigint operator-(const bigint &) const;
	bigint &operator+=(const bigint &);
	bigint &operator-=(const bigint &);
	bigint operator<<(unsigned int) const;
	bigint operator>>(unsigned int) const;
	bigint operator<<(const bigint &) const;
	bigint operator>>(const bigint &) const;
	bigint &operator<<=(unsigned int);
	bigint &operator>>=(unsigned int);
	bigint &operator<<=(const bigint &);
	bigint &operator>>=(const bigint &);
	bigint &operator++();
	bigint operator++(int);

	bool operator==(const bigint &) const;
	bool operator!=(const bigint &) const;
	bool operator<(const bigint &) const;
	bool operator<=(const bigint &) const;
	bool operator>(const bigint &) const;
	bool operator>=(const bigint &) const;
};

std::ostream &operator<<(std::ostream &, const bigint &);

#endif
