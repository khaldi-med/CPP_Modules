#pragma once

#include <string>
#include <iostream>

// bigint: arbitrary-precision unsigned integer stored as a decimal digit string.
// Invariant: _digits is never empty, never has leading zeros (except "0" itself).
class bigint {
private:
    std::string _digits; // most-significant digit first, e.g. 42 -> "42"

    // Helper: converts this bigint to a size_t.
    // Only used for shift amounts, which are always small in practice.
    size_t toSize_t() const;

public:
    // --- Constructors ---
    bigint();                       // Default: value 0
    bigint(long long n);            // From integer literal (42, 21, etc.)
    bigint(const bigint &other);    // Copy constructor

    // --- Assignment ---
    bigint &operator=(const bigint &other);

    // --- Arithmetic ---
    bigint  operator+ (const bigint &rhs) const;
    bigint &operator+=(const bigint &rhs);
    bigint  operator- (const bigint &rhs) const; // dummy: always returns 0

    // --- Increment ---
    bigint &operator++();    // prefix:  ++b  (modifies, returns *this)
    bigint  operator++(int); // postfix:  b++ (modifies, returns old value)

    // --- Decimal bit-shifts ---
    // << n appends n zeros:  43 << 3 == 43000
    // >> n removes n trailing digits: 43000 >> 3 == 43
    bigint  operator<< (const bigint &shift) const;
    bigint &operator<<=(const bigint &shift);
    bigint  operator>> (const bigint &shift) const;
    bigint &operator>>=(const bigint &shift);

    // --- Comparisons ---
    bool operator==(const bigint &rhs) const;
    bool operator!=(const bigint &rhs) const;
    bool operator< (const bigint &rhs) const;
    bool operator> (const bigint &rhs) const;
    bool operator<=(const bigint &rhs) const;
    bool operator>=(const bigint &rhs) const;

    // --- Stream output ---
    friend std::ostream &operator<<(std::ostream &os, const bigint &n);
};
