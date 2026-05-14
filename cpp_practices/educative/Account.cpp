#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Write classes code here
class Account {
  protected:
  float balance;
  
  public:
  Account(float b) {balance = b;}
  
 virtual void Withdraw(float amount) {}
 virtual void Deposit(float amount) {}
 virtual void printBalance() {}
};

// make base class functions virtual

class Savings: public Account {
  private:
  float interest_rate = 0.8;
  
  public:
  Savings(int bal): Account(bal) {}
  void Withdraw(float amount) {balance -= amount + (amount * interest_rate);}
  void Deposit(float amount) {balance += amount + (amount * interest_rate);}
  void printBalance() {cout<<"Balance in your saving account: "<<balance<<endl;}
};

class Current: public Account {
  public:
  Current(float bal): Account(bal) {}
  void Withdraw(float amount){balance -= amount;}
  void Deposit(float amount){balance += amount;}
  void printBalance(){cout<<"Balance in your current account: "<<balance<<endl;}
};

int main() {
  // creating savings account object
  Savings s1(50000);
  Account * acc = &s1;   // pointing acc to savings object
  acc->Deposit(1000);
  acc->printBalance();
  
  acc->Withdraw(3000);
  acc->printBalance();
  
  cout << endl;
  
  // creating current account object
  Current c1(50000);
  acc = &c1;     //// pointing acc to current object
  acc->Deposit(1000);
  acc->printBalance();
  
  acc->Withdraw(3000);
  acc->printBalance();  
}
