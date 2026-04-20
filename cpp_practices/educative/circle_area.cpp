#include <iostream>
using namespace std;

class Circle{
  private: 
    //declare the data member here
    int radius;

  public:
    Circle(){
     //write code for the default constructor here
     radius = 0;
    }
    Circle(int r){
     //write code for the parameterized constructor here
     radius = r;
    }
    void print_area(){
     //write code for print_area function here
      float pi = 3.14;
      float result = ((radius*radius) * pi);
      cout<<result<<endl;
    }
};


int main() {
  Circle c2(2);
  c2.print_area();
  return 0;
}
