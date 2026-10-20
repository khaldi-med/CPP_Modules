#include "vect2.hpp"
#include <iostream>
#include <iomanip>

/*
Should output this:
Constructors:
a = {0, 0}
b = {8, 9}
c = {3, 3}

Component access:
b[0] = 8, b[1] = 9
c[0] = 3, c[1] = 3
c[0] = 7, c[1] = 3

Scalar operations:
a = {3, 3}
2 * a = {6, 6}
a * 2 = {6, 6}
b + 2 = {10, 11}
2 + b = {10, 11}

Compound operations:
a += b += c : a = {10, 6}, b = {9, 5}
b = {9, 5}
c = {7, 3}
a = {5, 5}
a -= 2 : {3, 3}
a = {3, 3}
b = {9, 5}
a -= b : {-6, -2}

a = {-6, -2}
b = {9, 5}
c = {7, 3}
a = b * c + 2 : {65, 17}
a = 2 + b * c : {65, 17}

Increment / Decrement:
a = {1, 1}
a++ = {1, 1}
a = {2, 2}
++a = {3, 3}
a-- = {3, 3}
a = {2, 2}
--a = {1, 1}

Comparisons:
b == c : 1
b != c : 0
*/

int main()
{
    // Testing constructors
    vect2 a;
    vect2 b(8, 9);
    vect2 c(3, 3);

    std::cout << "Constructors:\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n\n";

    // Test operator[]
    std::cout << "Component access:\n";
    std::cout << "b[0] = " << b[0] << ", b[1] = " << b[1] << "\n";
    std::cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << "\n";
    c[0] = 7;
    std::cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << "\n\n";

    // Testing scalar operations
    std::cout << "Scalar operations:\n";
    a = vect2(3, 3);
    std::cout << "a = " << a << "\n";
    std::cout << "2 * a = " << 2 * a << "\n";
    std::cout << "a * 2 = " << a * 2 << "\n";
    std::cout << "b + 2 = " << b + 2 << "\n";
    std::cout << "2 + b = " << 2 + b << "\n\n";

    std::cout << "Compound operations:\n";
    a = vect2(1, 1);
    b = vect2(2, 2);
    a += b += c;
    std::cout << "a += b += c : a = " << a << ", b = " << b << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";

    a = vect2(5, 5);
    std::cout << "a = " << a << "\n";
    a -= 2;
    std::cout << "a -= 2 : " << a << "\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    a -= b;
    std::cout << "a -= b : " << a << "\n\n";

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    a = b * c + 2;
    std::cout << "a = b * c + 2 : " << a << "\n";
    a = 2 + b * c;
    std::cout << "a = 2 + b * c : " << a << "\n\n";

    std::cout << "Increment / Decrement:\n";
    a = vect2(1, 1);
    std::cout << "a = " << a << "\n";
    std::cout << "a++ = " << a++ << "\n";
    std::cout << "a = " << a << "\n";
    std::cout << "++a = " << ++a << "\n";
    std::cout << "a-- = " << a-- << "\n";
    std::cout << "a = " << a << "\n";
    std::cout << "--a = " << --a << "\n\n";

    vect2 f(2,3);
    vect2 g(2,3);
    std::cout << "Comparisons:\n";
    std::cout << "b == c : " << (g == f) << "\n";
    std::cout << "b != c : " << (g != f) << "\n";

    return 0;
}