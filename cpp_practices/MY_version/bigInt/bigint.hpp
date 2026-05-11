#include <iostream>
#include <ostream>
#include <string>

class Bigint {
  std::string _digit;

  public:
    Bigint();
    Bigint(long long n);
    Bigint(const Bigint &other);
  friend std::ostream &operator<<(std::ostream &os, const Bigint &n);
};

