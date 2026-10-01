#pragma once
#include <string>

class BigInt{
  private:
  std::string _digit;
  public:
    BigInt();
    BigInt(long long n);
    BigInt(const std::string& str);
    BigInt(const BigInt& oth);
    BigInt& operator=(const BigInt& oth);
    
    //arithmetic operators
    BigInt operator+(const BigInt& oth) const;
    BigInt &operator+=(const BigInt& oth);
    BigInt operator-(const BigInt& oth);

    ////increment operators
    BigInt &operator++();
    BigInt operator++(int);

    ////shift operators
    BigInt operator<<(const BigInt& oth) const;
    Bigint operator>>(const BigInt& oth) const;
    //Bigint &operator<<=(const BigInt& oth);
    //Bigint &operator>>=(const BigInt& oth);
    
    ////comparison operators
    //bool operator<(const BigInt& oth) const;
    //bool operator>(const BigInt& oth) const;
    //bool operator==(const BigInt& oth) const;
    //bool operator!=(const BigInt& oth) const;
    //bool operator<=(const BigInt& oth) const;
    //bool operator>=(const BigInt& oth) const;
    
    ~BigInt();

friend std::ostream& operator<<(std::ostream &os, const BigInt& oth);
};

