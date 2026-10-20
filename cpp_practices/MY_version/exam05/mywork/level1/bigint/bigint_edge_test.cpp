#include "bigint.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

static std::string text(const bigint &value)
{
    std::ostringstream output;
    output << value;
    return output.str();
}

static void expect(const std::string &name, const std::string &actual,
                   const std::string &wanted)
{
    if (actual != wanted) {
        std::cerr << "FAIL: " << name << "\n"
                  << "  expected: " << wanted << "\n"
                  << "  actual:   " << actual << "\n";
        std::exit(EXIT_FAILURE);
    }
    std::cout << "PASS: " << name << "\n";
}

static void expect_bool(const std::string &name, bool actual, bool wanted)
{
    expect(name, actual ? "true" : "false", wanted ? "true" : "false");
}

int main()
{
    // Constructors, copies, assignment, and canonical zero formatting.
    expect("default constructor", text(bigint()), "0");
    expect("zero constructor", text(bigint(0)), "0");
    expect("number constructor", text(bigint(123456789)), "123456789");
    expect("leading zeroes", text(bigint("0000012300")), "12300");
    expect("all zeroes", text(bigint("000000")), "0");
    expect("empty string", text(bigint("")), "0");
    expect("copy constructor", text(bigint(bigint(42))), "42");

    bigint assigned;
    assigned = bigint("987654321");
    expect("assignment", text(assigned), "987654321");
    assigned = assigned;
    expect("self assignment", text(assigned), "987654321");

    // Addition, including carry propagation and self-addition.
    expect("addition", text(bigint(42) + bigint(21)), "63");
    expect("addition with zero", text(bigint(42) + bigint(0)), "42");
    expect("different lengths", text(bigint("999") + bigint(1)), "1000");
    expect("long carry", text(bigint("999999999999999999") + bigint(1)),
           "1000000000000000000");

    bigint sum("999");
    expect("plus assignment", text(sum += bigint(1)), "1000");
    expect("self addition", text(sum += sum), "2000");

    // Subtraction is intentionally the exam's required placeholder behavior.
    expect("subtraction placeholder", text(bigint(123) - bigint(23)), "0");

    // Prefix and postfix increment.
    bigint counter("999");
    expect("prefix increment", text(++counter), "1000");
    expect("postfix returned value", text(counter++), "1000");
    expect("postfix stored value", text(counter), "1001");

    // Left digit shifts.
    expect("left shift zero", text(bigint(0) << 10), "0");
    expect("left shift by zero", text(bigint(42) << 0), "42");
    expect("left shift", text(bigint(42) << 3), "42000");
    expect("left shift bigint amount", text(bigint(42) << bigint(3)), "42000");

    bigint shifted_left(42);
    expect("left shift assignment", text(shifted_left <<= 3), "42000");
    expect("left shift bigint assignment",
           text(shifted_left <<= bigint(1)), "420000");

    // Right digit shifts, including shifts beyond the number length.
    expect("right shift zero", text(bigint(0) >> 10), "0");
    expect("right shift by zero", text(bigint(1337) >> 0), "1337");
    expect("right shift", text(bigint(1337) >> 2), "13");
    expect("right shift to one digit", text(bigint(1337) >> 3), "1");
    expect("right shift to zero", text(bigint(1337) >> 4), "0");
    expect("large right shift", text(bigint(1337) >> 1000000), "0");
    expect("right shift bigint amount", text(bigint(1337) >> bigint(2)), "13");

    bigint shifted_right("1337");
    expect("right shift assignment", text(shifted_right >>= 2), "13");
    expect("right shift bigint assignment",
           text(shifted_right >>= bigint(1)), "1");
    expect("right shift assignment to zero",
           text(shifted_right >>= 100), "0");

    // Comparisons for equal values, different lengths, and close values.
    const bigint equal_a("00042");
    const bigint equal_b(42);
    const bigint smaller(41);
    const bigint larger(43);
    expect_bool("equal <", equal_a < equal_b, false);
    expect_bool("equal <=", equal_a <= equal_b, true);
    expect_bool("equal ==", equal_a == equal_b, true);
    expect_bool("equal >=", equal_a >= equal_b, true);
    expect_bool("equal >", equal_a > equal_b, false);
    expect_bool("equal !=", equal_a != equal_b, false);
    expect_bool("smaller <", smaller < equal_b, true);
    expect_bool("larger >", larger > equal_b, true);
    expect_bool("different lengths", bigint("999") < bigint("1000"), true);

    // Large values must not depend on built-in integer limits.
    expect("large shift and addition",
           text((bigint("999999999999999999999") << 5) + bigint(1)),
           "99999999999999999999900001");

    // Confirm the maximum size_t constructor value is represented correctly.
    std::ostringstream max_value;
    max_value << std::numeric_limits<size_t>::max();
    expect("maximum size_t", text(bigint(std::numeric_limits<size_t>::max())),
           max_value.str());

    std::cout << "All bigint edge tests passed.\n";
    return EXIT_SUCCESS;
}
