#ifndef PLANET_H
#define PLANET_H

class Planet {
  double radius;
  double mass;
  double G;
  
  public:
  Planet();
  Planet(double r, double m);
  double calculateGravity();
  double getMass();
  void setMass(double m);
  double getRadius();
  void setRadius(double r);
};
#endif
