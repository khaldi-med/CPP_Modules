#include <iostream>
using namespace std;

// Write classes code here
class Animal{
  public:
  string name;
  string sound;

  Animal(string Aname, string Asound): name(Aname), sound(Asound) {};
  
  void Animal_Details(){
    cout << "Animal Name: "<< name << endl;
    cout << "Animal Sound: "<< sound << endl;
  }
};

class Dog: public Animal {
  string family;
  public:  
  Dog(string Dname, string Dsound, string Dfamily): Animal(Dname, Dsound) {
    family = Dfamily;
  }
  
  void  Dog_detail(){
    Animal_Details();
    cout << "Dog's Family: " << family << endl;
  }
};

class Sheep: public Animal {
  string color;
  public:
  Sheep(string Sname, string Ssound, string Scolor): Animal(Sname, Ssound) {
    color = Scolor;
  };
  
  void Sheep_detail(){
    Animal_Details();
  }
};

int main() {
  // Make classes objects here
  Dog d("Pongo", "Woof Woof", "Canine");
  d.Dog_detail();
  cout << endl;
  Sheep s("Billy", "Baaa Baaa", "White");
  s.Sheep_detail();
}
