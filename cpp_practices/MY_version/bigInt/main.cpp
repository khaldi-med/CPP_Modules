#include "bigint.hpp"
#include <iostream>

int main() {
    Bigint a(42);
    Bigint b(1337);
    Bigint c;
    Bigint d(b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}
