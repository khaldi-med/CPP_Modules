#include <iostream>
#include <cmath>
using namespace std;

class Point {

  // Private fields
  private:
  int x;
  int y;

  public:
  // Default Constructor
  Point() {
    x = 0;
    y = 0;
  }
  // Parameterized Constructor
  Point(int x, int y) { 
    // Implement the function
    this->x = x;
    this->y = y;
  }

  double distance() {
    // Implement the function
    return sqrt(pow((x - 0),2) + pow((y - 0), 2));
  }

  double distance(int x2, int y2) {
    // Implement the function
    return sqrt(pow((x2 - x),2) + pow((y2 - y), 2));
  }

};


int main() {
  Point p(1, 2);
  cout << p.distance() << endl;
  cout << p.distance(3, 4) << endl;
  return 0;
}
