#include <iostream>
using namespace std;

void isPrime(int n) {
   //write your code here
   bool isPrime = true;
   for(int i = 2; i < n; i++) {
     if(n % i == 0) {
       isPrime = false;
       break;
     }
   }
   if(isPrime) {
     cout << n << " is a prime number";
   } else {
     cout << n << " is not a prime number";
   }
}


int main() {
  int n = 0;
  isPrime(n);
  return 0;
}
