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

Savings::Savings(float b, float ir): {Account::balance(b);ir=0.8;}

Current::Current(float b): Account::balance(b),  {}

int main() {
  // make instances of classes here
  // call their traits functions here
  Savings s1(50000);
  Account * acc = &s1;
  acc->Deposit(1000);
  acc->printBalance();
  
  acc->Withdraw(3000);
  acc->printBalance();
  
  
  Current c1(50000);
  acc = &c1;
  acc->Deposit(1000);
  acc->printBalance();
  
  acc->Withdraw(3000);
  acc->printBalance(); 
  return 0;
}
