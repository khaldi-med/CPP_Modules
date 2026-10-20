#include "vect2.hpp"

vect2 operator+(int n, const vect2 &v) { return v + n; }
vect2 operator-(int n, const vect2 &v) { return vect2(n - v[0], n - v[1]); }
vect2 operator*(int n, const vect2 &v) { return v * n; }
std::ostream &operator<<(std::ostream &out, const vect2 &v)
{
	return out << "{" << v[0] << ", " << v[1] << "}";
}
