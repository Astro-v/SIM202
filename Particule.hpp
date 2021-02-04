#ifndef PARTICULE_HPP
#define PARTICULE_HPP


#include <iostream>
using namespace std;

class Particule{
  public:
    double masse;
    double x;
    double y;
    Particule(double x_,double y_, double m){x = x_; y = y_; masse = m;}

};

#endif //PARTICULE_HPP
