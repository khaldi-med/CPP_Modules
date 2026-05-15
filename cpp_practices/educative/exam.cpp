#include <iostream>
#include <string>
using namespace std;

class Shape {
   private:
   string color;
   public:
   void setColor(string c){
       //write your code here
       color = c;
   }
   string getColor(){
       //write your code here
       return color;
   }
};

class Square : public Shape {

   int length, width;
   public:
    Square(int l, int w){
       //write your code here
       length = l;
       width = w;
    }

    void display_area() {
        //write your code here
        int area = width*length;
        cout<<"The area of the square is:"<< area<<endl;
    }

    void displayColor() {
        //write your code here
        cout<<"The color of the square is: "<< getColor()<<endl;
    }
};

int main(){
Square sq(4,3);
sq.setColor("red");
sq.display_area();
sq.displayColor();
}

