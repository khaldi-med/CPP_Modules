#include <iostream>
#include "bigint.hpp"

/*
Should output this:
24210010421060
num1 + num2 = 252
num3 += num2: 252
num8 == num9: 0
num8 != num9: 1
num8 < num9: 1
num8 <= num9: 1
num8 > num9: 0
num8 >= num9: 0
num1 << 2 = 425400
num1 >> 2 = 0
num1 << num5 = 42
num1 >> num5 = 425400
num12++ = 2
num12 = 3
++num12 = 4
num12 = 4
num1 << numC = 4254000000000000000000000000000000000000000000000000000000000000
num1 >> numC = 0
num3 <<= 2: 24200
num3 >>= 1: 2420
num3 <<= num5: 2420000000000
num3 >>= num5: 242
*/

int main() {
    // Creating bigints
    bigint num1("000242"), num2("0010"), num3, num4(1042);
    bigint num5 = num2;
    const bigint numC(60);

    // Testing arithmetic operators
    std::cout << num1 << num2 << num3 << num4 << num5 << numC << std::endl;
    std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
    num3 = num1;
    num3 += num2;
    std::cout << "num3 += num2: " << num3 << std::endl;

    bigint num8("999"), num9("9990");

    // Testing comparison operators
    std::cout << "num8 == num9: " << (num8 == num9) << std::endl;
    std::cout << "num8 != num9: " << (num8 != num9) << std::endl;
    std::cout << "num8 < num9: " << (num8 < num9) << std::endl;
    std::cout << "num8 <= num9: " << (num8 <= num9) << std::endl;
    std::cout << "num8 > num9: " << (num8 > num9) << std::endl;
    std::cout << "num8 >= num9: " << (num8 >= num9) << std::endl;

    bigint num10("4254");
    // Testing digit shift operators with integers
    std::cout << "num1 << 2 = " << (num10 << 2) << std::endl;
    std::cout << "num1 >> 2 = " << (num10 >> 4) << std::endl;

    bigint num11("2");
    // Testing digit shift operators with bigint
    std::cout << "num1 << num5 = " << (num10 >> num11) << std::endl;
    std::cout << "num1 >> num5 = " << (num10 << num11) << std::endl;

    bigint num12("2");
    // Testing increment operators
    std::cout << "num12++ = " << (num12++) << std::endl;
    std::cout << "num12 = " << (num12) << std::endl;
    std::cout << "++num12 = " << (++num12) << std::endl;
    std::cout << "num12 = " << (num12) << std::endl;

    // Testing digit shift operators with constant bigint
    std::cout << "num1 << numC = " << (num10 << numC) << std::endl;
    std::cout << "num1 >> numC = " << (num10 >> numC) << std::endl;

    // Testing compound assignments with shifts
    num3 = num1;
    num3 <<= 2;
    std::cout << "num3 <<= 2: " << num3 << std::endl;
    num3 >>= 1;
    std::cout << "num3 >>= 1: " << num3 << std::endl;

    // Testing compound assignments with bigint
    num3 = num1;
    num3 <<= num5;
    std::cout << "num3 <<= num5: " << num3 << std::endl;
    num3 >>= num5;
    std::cout << "num3 >>= num5: " << num3 << std::endl;

    return 0;
}
