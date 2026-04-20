  #include "Planet.hpp"
  #include <iostream>
  
  Planet::Planet():  G (6.67e-11){};

  Planet::Planet(double r, double m){
    radius = r;
    mass = m;
  }
  
  double  Planet::getMass(){
    return mass;
  }
  
  void  Planet::setMass(double m){
    mass = m;
  }
  
  double  Planet::getRadius(){
    return radius;
  }
  
  void  Planet::setRadius(double r){
    radius = r;
  }
  
  double Planet::calculateGravity(){
    double gravity = (G * mass)/(radius * radius);
    return gravity;
  }
