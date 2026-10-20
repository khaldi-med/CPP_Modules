#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>
#include <vector>

class vect2 {
	std::vector<int> v;

	public:
	vect2()
	{
		v.push_back(0);
		v.push_back(0);
	}

	vect2(int x, int y)
	{
		v.push_back(x);
		v.push_back(y);
	}

	vect2 &operator=(const vect2 &oth)
	{
		if (this != &oth)
			v = oth.v;
		return *this;
	}

	~vect2() {}

	vect2 (const vect2 &oth)
	{
		v.push_back(oth.v[0]);
		v.push_back(oth.v[1]);
	}
	
	const int &operator[](size_t i) const
	{
		return v[i];
	}

	int &operator[](size_t i)
	{
		return v[i];
	}

	vect2 &operator++()
	{
		*this += 1;
		return *this;
	}

	vect2 operator++(int)
	{
		vect2 tmp = *this;
		++*this;
		return tmp;
	}

	vect2 &operator--()
	{
		*this -= 1;
		return *this;
	}

	vect2 operator--(int)
	{
		vect2 tmp = *this;
		--*this;
		return tmp;
	}

	vect2 operator+(int n) const
	{
		return vect2(v[0] + n, v[1] + n);
	}

	vect2 operator+(const vect2 &oth) const
	{
		return vect2(v[0] + oth[0], v[1] + oth[1]);
	}
	
	vect2 operator-(int n) const
	{
		return vect2(v[0] - n, v[1] - n);
	}

	vect2 operator-(const vect2 &oth) const
	{
		return vect2(v[0] - oth[0], v[1] - oth[1]);
	}

	vect2 operator*(int n) const
	{
		return vect2(v[0] * n, v[1] * n);
	}

	vect2 operator*(const vect2 &oth) const
	{
		return vect2(v[0] * oth[0], v[1] * oth[1]);
	}

	vect2 &operator+=(int n)
	{
		*this = *this + n;
		return *this;
	}

	vect2 &operator+=(const vect2 &oth)
	{
		*this = *this + oth;
		return *this;	
	}

	vect2 &operator-=(int n)
	{
		*this = *this - n;
		return *this;
	}

	vect2 &operator-=(const vect2 &oth)
	{
		*this = *this - oth;
		return *this;
	}

	vect2 &operator*=(int n)
	{
		*this = *this * n;
		return *this;
	}

	vect2 &operator*=(const vect2 &oth)
	{
		*this = *this * oth;
		return *this;
	}

	vect2 operator-() const
	{
		return vect2(-v[0], -v[1]);
	}

	bool operator==(const vect2 &oth) const
	{
		return v == oth.v;
	}

	bool operator!=(const vect2 &oth) const
	{
		return v != oth.v;
	}

	bool operator<(const vect2 &oth) const
	{
		return v < oth.v;
	}

	bool operator<=(const vect2 &oth) const
	{ 
		return v <= oth.v;
	}

	bool operator>(const vect2 &oth) const
	{
		return v > oth.v;
	}

	bool operator>=(const vect2 &oth) const
	{
		return v >= oth.v;
	}

	int getX() const
	{
		return v[0];
	}

	int getY() const
	{
		return v[1];
	}
};

std::ostream &operator<<(std::ostream &os, const vect2 &v);
vect2 operator+(int n, const vect2 &v);
vect2 operator-(int n, const vect2 &v);
vect2 operator*(int n, const vect2 &v);

#endif