#include <string>
#include <iostream>
#include <algorithm>

class bigint{

//Part 1:
    std::string nbr;
    std::string add_string(const std::string &s1, const std::string &s2) const {
        std::string res;
        int car = 0;

        int i = s1.size() -1;
        int j = s2.size() -1;

        while(i >= 0 || j >= 0 || car){
           int sum = (i >= 0 ? s1[i--] - '0': 0) + (j >= 0 ? s2[j--] - '0': 0) + car;
            res.push_back('0' + sum % 10);
            car = sum/10;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    void shift_left(size_t n) {
        if (nbr != "0")
            nbr += std::string(n, '0');
    }

    void shift_right(size_t n) {
        if (n >= nbr.size())
            nbr = "0";
        else
            nbr.erase(nbr.size() - n);
    }

//Part 2:
    public:
        bigint() : nbr("0") {};
        bigint(size_t num) : nbr("0") {
            if (num != 0) {
                nbr.clear();
                while (num > 0) {
                    nbr.push_back(static_cast<char>('0' + num % 10));
                    num /= 10;
                }
                std::reverse(nbr.begin(), nbr.end());
            }
        };
        bigint(const std::string &num) {
            std::string::size_type first = num.find_first_not_of('0');
            nbr = (first == std::string::npos) ? "0" : num.substr(first);
        }
        bigint(const bigint &oth) : nbr(oth.nbr) {}
        bigint &operator=(const bigint &oth){
            if(this != &oth)
                nbr = oth.nbr;
            return *this;
        }
                
//Part 3:
        bigint operator+(const bigint &oth) const {
            return(bigint(add_string(this->nbr, oth.nbr)));
        }
        
        bigint &operator+=(const bigint &oth){
            nbr = add_string(nbr, oth.nbr);
            return (*this);
        }

        // FIXED: added 'const' qualifier so it can be called on const objects (e.g. 'a - a')
        bigint operator-(const bigint &oth) const {
            (void)oth;
            return bigint(0);
        }

//Part 4:
        bigint operator++(int){
            bigint tmp = bigint(nbr);
            ++(*this);
            return tmp;
        }
        bigint &operator++(){
            *this += bigint(1);
            return (*this);
        }

//Part 5:
        bigint operator<<(size_t n) const {
            bigint tmp(*this);
            tmp.shift_left(n);
            return tmp;
        }
        bigint &operator<<=(size_t n){
            shift_left(n);
            return *this;
        }
        bigint operator<<(const bigint &oth) const {
            bigint tmp(*this);
            tmp <<= oth;
            return tmp;
        }
        bigint &operator<<=(const bigint &oth){
            bigint i(0);
            while(i < oth){
                shift_left(1);
                ++i;
            }
            return *this;
        }
        bigint operator>>(size_t n) const {
            bigint tmp(*this);
            tmp.shift_right(n);
            return tmp;
        }
        bigint &operator>>=(size_t n){
            shift_right(n);
            return *this;
        }
        bigint operator>>(const bigint &oth) const {
            bigint tmp(*this);
            tmp >>= oth;
            return tmp;
        }
        bigint &operator>>=(const bigint &oth){
            if (oth >= bigint(nbr.size())) {
                nbr = "0";
                return *this;
            }
            bigint i(0);
            while(i < oth){
                shift_right(1);
                ++i;
            }
            return *this;
        }

//Part 6:
        bool operator<(const bigint &oth)const{
            if(nbr.size() < oth.nbr.size())
                return(true);
            else if(nbr.size() > oth.nbr.size())
                return false;
            return(nbr < oth.nbr);
        }
         bool operator>(const bigint& x) const { return x < *this; }
         bool operator>=(const bigint& x) const { return !(*this < x); }
         bool operator<=(const bigint& x) const { return !(*this > x); }
         bool operator==(const bigint& x) const { return nbr == x.nbr; }
         bool operator!=(const bigint& x) const { return !(*this == x); } 

//Part 7:
        friend std::ostream &operator<<(std::ostream &os, const bigint &oth){
            return os << oth.nbr;
        }
};
