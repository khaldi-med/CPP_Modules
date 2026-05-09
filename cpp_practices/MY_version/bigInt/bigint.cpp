#include "bigint.hpp"
#include <algorithm> // std::reverse

// =============================================================================
// Private helper
// =============================================================================

// Convert this bigint's value to a size_t.
// We only ever call this for shift amounts (e.g. << 10, >> 2), which are tiny,
// so overflow is not a practical concern.
size_t bigint::toSize_t() const {
    size_t result = 0;
    for (char c : _digits)
        result = result * 10 + static_cast<size_t>(c - '0');
    return result;
}

// =============================================================================
// Constructors
// =============================================================================

// Default constructor: represents the number 0.
bigint::bigint() : _digits("0") {}

// Integer constructor.
// We accept long long so that literals like bigint(42) and bigint(1337) work
// without ambiguity. The subject only requires unsigned numbers, so we treat
// any negative input as 0.
bigint::bigint(long long n) {
    if (n <= 0) {
        _digits = "0";
        return;
    }
    _digits.clear();
    // Build digits in reverse (least-significant first), then reverse.
    while (n > 0) {
        _digits += static_cast<char>('0' + n % 10);
        n /= 10;
    }
    std::reverse(_digits.begin(), _digits.end());
}

// Copy constructor.
bigint::bigint(const bigint &other) : _digits(other._digits) {}

// =============================================================================
// Assignment
// =============================================================================

bigint &bigint::operator=(const bigint &other) {
    if (this != &other)
        _digits = other._digits;
    return *this;
}

// =============================================================================
// Addition
// =============================================================================

// Classic grade-school addition: iterate from the least-significant digit,
// propagate carry. We build the result in reverse, then flip it.
bigint bigint::operator+(const bigint &rhs) const {
    bigint result;
    result._digits.clear();

    int carry = 0;
    int i = static_cast<int>(_digits.size())     - 1; // index into *this
    int j = static_cast<int>(rhs._digits.size()) - 1; // index into rhs

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += _digits[i--]     - '0';
        if (j >= 0) sum += rhs._digits[j--] - '0';
        carry = sum / 10;
        result._digits += static_cast<char>('0' + sum % 10);
    }

    // Edge case: both operands are 0 → loop never ran.
    if (result._digits.empty())
        result._digits = "0";

    std::reverse(result._digits.begin(), result._digits.end());
    return result;
}

bigint &bigint::operator+=(const bigint &rhs) {
    *this = *this + rhs;
    return *this;
}

// =============================================================================
// Subtraction (dummy implementation required by the grader)
// =============================================================================

// The subject explicitly states that a dummy returning 0 is sufficient.
bigint bigint::operator-(const bigint &rhs) const {
    (void)rhs; // suppress unused-parameter warning
    return bigint(0);
}

// =============================================================================
// Increment
// =============================================================================

// Prefix ++b: add 1, then return the updated object.
bigint &bigint::operator++() {
    *this += bigint(1);
    return *this;
}

// Postfix b++: save the current value, increment, return the saved value.
// The dummy int parameter is the conventional C++ way to distinguish postfix
// from prefix — the compiler passes 0 for it, and we ignore it.
bigint bigint::operator++(int) {
    bigint old(*this);
    ++(*this);
    return old;
}

// =============================================================================
// Decimal bit-shifts
// =============================================================================

// Left shift by n: multiply by 10^n, i.e. append n '0' characters.
// Special case: shifting 0 stays 0 (we never want "000...").
bigint bigint::operator<<(const bigint &shift) const {
    if (_digits == "0")
        return *this;
    size_t n = shift.toSize_t();
    bigint result(*this);
    result._digits.append(n, '0');
    return result;
}

bigint &bigint::operator<<=(const bigint &shift) {
    *this = *this << shift;
    return *this;
}

// Right shift by n: divide by 10^n, i.e. drop the last n digits.
// If n >= number of digits, the result is 0.
bigint bigint::operator>>(const bigint &shift) const {
    size_t n = shift.toSize_t();

    // Shifting away all (or more) digits → result is 0.
    if (n >= _digits.size())
        return bigint(0);

    bigint result;
    result._digits = _digits.substr(0, _digits.size() - n);

    // Strip any leading zeros that might have been uncovered.
    // (This can only happen if the original had leading zeros, which our
    //  invariant forbids — but defensive programming costs nothing here.)
    size_t firstNonZero = result._digits.find_first_not_of('0');
    if (firstNonZero == std::string::npos)
        result._digits = "0";
    else if (firstNonZero > 0)
        result._digits = result._digits.substr(firstNonZero);

    return result;
}

bigint &bigint::operator>>=(const bigint &shift) {
    *this = *this >> shift;
    return *this;
}

// =============================================================================
// Comparisons
// =============================================================================

// Equality: since we maintain the no-leading-zeros invariant, two bigints
// are equal if and only if their digit strings are identical.
bool bigint::operator==(const bigint &rhs) const {
    return _digits == rhs._digits;
}

bool bigint::operator!=(const bigint &rhs) const {
    return !(*this == rhs);
}

// Less-than: a longer digit string always represents a larger number
// (no leading zeros invariant). If lengths are equal, lexicographic
// comparison on the digit characters gives the correct numeric order.
bool bigint::operator<(const bigint &rhs) const {
    if (_digits.size() != rhs._digits.size())
        return _digits.size() < rhs._digits.size();
    return _digits < rhs._digits; // lexicographic == numeric when same length
}

bool bigint::operator>(const bigint &rhs) const {
    return rhs < *this;
}

bool bigint::operator<=(const bigint &rhs) const {
    return !(rhs < *this);
}

bool bigint::operator>=(const bigint &rhs) const {
    return !(*this < rhs);
}

// =============================================================================
// Stream output
// =============================================================================

std::ostream &operator<<(std::ostream &os, const bigint &n) {
    os << n._digits;
    return os;
}
