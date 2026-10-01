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
  
 virtual void Withdraw(float amount) = 0;
 virtual void Deposit(float amount) = 0;
 virtual void printBalance() = 0;
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
  Account * acc[2];
  acc[0] = new Savings(50000);  
  acc[0]->Deposit(1000);
  acc[0]->printBalance();
  
  acc[0]->Withdraw(3000);
  acc[0]->printBalance();
  
  acc[1] = new Current(50000);
  acc[1]->Deposit(1000);
  acc[1]->printBalance();
  
  acc[1]->Withdraw(3000);
  acc[1]->printBalance();   
}
