#include <string>
#include <iostream>
#include <algorithm>

class bigint
{
private:
    std::string nbr;

    std::string add_string(const std::string& s1, const std::string& s2) const
    {
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
        std::string res;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::string sub_string(const std::string& s1, const std::string& s2) const
    {
        int i = s1.size() - 1, j = s2.size() - 1, borrow = 0;
        std::string res;
        while (i >= 0)
        {
            int sub = (s1[i] - '0') - borrow;
            if (j >= 0)
                sub -= (s2[j] - '0');
            if (sub < 0)
            {
                sub += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            res.push_back(sub + '0');
            i--;
            j--;
        }
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();
        std::reverse(res.begin(), res.end());
        return res;
    }

public:
    bigint() : nbr("0") {}
    bigint(size_t num) : nbr(std::to_string(num)) {}
    bigint(const std::string& num) : nbr(num) {}

    friend std::ostream& operator<<(std::ostream& os, const bigint& b)
    {
        return os << b.nbr;
    }

    bigint operator+(const bigint& b) const
    {
        return bigint(add_string(nbr, b.nbr));
    }

    bigint& operator+=(const bigint& b)
    {
        nbr = add_string(nbr, b.nbr);
        return *this;
    }

    bigint operator-(const bigint& b) const
    {
        if (*this < b)
            return bigint("0");
        return bigint(sub_string(nbr, b.nbr));
    }

    bigint& operator-=(const bigint& b)
    {
        *this = *this - b;
        return *this;
    }

    bigint& operator++()
    {
        *this += bigint(1);
        return *this;
    }

    bigint operator++(int)
    {
        bigint tmp(*this);
        ++(*this);
        return tmp;
    }

    bigint operator<<(size_t sh) const
    {
        if (nbr == "0") return *this;
        return bigint(nbr + std::string(sh, '0'));
    }

    bigint& operator<<=(size_t sh)
    {
        if (nbr != "0") nbr += std::string(sh, '0');
        return *this;
    }

    bigint& operator>>=(const bigint& shift)
    {
        if (bigint(nbr.size()) < shift || nbr == "0")
        {
            nbr = "0";
        }
        else
        {
            bigint i(0);
            while (i < shift)
            {
                nbr.pop_back();
                ++i;
            }
            if (nbr.empty()) nbr = "0";
        }
        return *this;
    }

    bool operator<(const bigint& b) const
    {
        if (nbr.size() != b.nbr.size())
            return nbr.size() < b.nbr.size();
        return nbr < b.nbr;
    }

    bool operator>(const bigint& b) const { return b < *this; }
    bool operator==(const bigint& b) const { return nbr == b.nbr; }
    bool operator!=(const bigint& b) const { return !(*this == b); }
    bool operator>=(const bigint& b) const { return !(*this < b); }
    bool operator<=(const bigint& b) const { return !(*this > b); }
};

int main(){
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "a+b " << a + b << std::endl;
    std::cout << "c+=a " << (c += a) << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "++b " << ++b << std::endl;
    std::cout << "b++ " << b++ << std::endl;
    std::cout << "(b << 10) + 42 " << (b << 10) + 42 << std::endl;
    std::cout << "d<<=4 " << (d <<= 4) << std::endl;
    std::cout << "d>>=(const bigint)2 " << (d >>= (const bigint)2) << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "a - d = " << a - d << std::endl;
    std::cout << "d < a " << (d < a) << std::endl;
    std::cout << "d > a " << (d > a) << std::endl;
    std::cout << "d == a " << (d == a) << std::endl;
    std::cout << "d != a " << (d != a) << std::endl;
    std::cout << "d <= a " << (d <= a) << std::endl;
    std::cout << "d >= a " << (d >= a) << std::endl;

    return 0;
}
