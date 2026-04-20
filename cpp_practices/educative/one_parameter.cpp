#include <iostream>
using namespace std;

void cube(int *a){ 
  if(a != NULL){
    *a = (*a) * (*a) * (*a);
  }
}

int main() {
  int *p = new int(2);
  cube(p);
  cout << *p;
}
