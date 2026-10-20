#include "vect2.hpp"

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
        os << "{" << v.getX() << ", " << v.getY() << "}";
        return os;
}

vect2 operator+(int n, const vect2 &v)
{
        return vect2(n + v.getX(), n + v.getY());
}

vect2 operator-(int n, const vect2 &v)
{
        return vect2(n - v.getX(), n - v.getY());
}

vect2 operator*(int n, const vect2 &v)
{
        return vect2(n * v.getX(), n * v.getY());
}