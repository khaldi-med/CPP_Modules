#include <iostream>
using namespace std;

// Write classes code here
class Account {
  protected:
  float balance;
  
  public:
  void Withdraw(float amount);
  void Deposit(float amount);
  void printBalance();
};
// make base class functions virtual

class Savings: public Account {
  private:
  float interest_rate;
  
  public:
  void Withdraw(float amount);
  void Deposit(float amount);
  void printBalance();
};

class Current: public Account {
  private:
  float interest_rate;
  
  public:
  void Withdraw(float amount);
  void Deposit(float amount);
  void printBalance();
};

int main() {
  // make instances of classes here
  // call their traits functions here
  return 0;
}
