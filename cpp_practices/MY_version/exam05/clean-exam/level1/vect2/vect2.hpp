#ifndef VECT2_HPP
#define VECT2_HPP

#include <cstddef>
#include <iostream>

class vect2 {
	int x, y;
public:
	vect2(int x = 0, int y = 0) : x(x), y(y) {}
	int &operator[](std::size_t i) { return i ? y : x; }
	const int &operator[](std::size_t i) const { return i ? y : x; }
	vect2 operator+(const vect2 &v) const { return vect2(x + v.x, y + v.y); }
	vect2 operator-(const vect2 &v) const { return vect2(x - v.x, y - v.y); }
	vect2 operator*(int n) const { return vect2(x * n, y * n); }
	vect2 operator+(int n) const { return vect2(x + n, y + n); }
	vect2 operator-(int n) const { return vect2(x - n, y - n); }
	vect2 &operator+=(const vect2 &v) { return *this = *this + v; }
	vect2 &operator-=(const vect2 &v) { return *this = *this - v; }
	vect2 &operator*=(int n) { return *this = *this * n; }
	vect2 &operator+=(int n) { return *this = *this + n; }
	vect2 &operator-=(int n) { return *this = *this - n; }
	vect2 &operator++() { return *this += 1; }
	vect2 operator++(int) { vect2 old(*this); ++*this; return old; }
	vect2 &operator--() { return *this -= 1; }
	vect2 operator--(int) { vect2 old(*this); --*this; return old; }
	vect2 operator-() const { return vect2(-x, -y); }
	bool operator==(const vect2 &v) const { return x == v.x && y == v.y; }
	bool operator!=(const vect2 &v) const { return !(*this == v); }
	bool operator<(const vect2 &v) const { return x != v.x ? x < v.x : y < v.y; }
	bool operator<=(const vect2 &v) const { return !(v < *this); }
	bool operator>(const vect2 &v) const { return v < *this; }
	bool operator>=(const vect2 &v) const { return !(*this < v); }
};

vect2 operator+(int n, const vect2 &v);
vect2 operator-(int n, const vect2 &v);
vect2 operator*(int n, const vect2 &v);
std::ostream &operator<<(std::ostream &, const vect2 &);

#endif
