#ifndef BOITE_HPP
#define BOITE_HPP


#include <iostream>
#include "Particule.hpp"
using namespace std;

class Boite {
  private:
    int niveau;
    double centre_x;
    double centre_y;
    double centre_masse_x;
    double centre_masse_y;
    double masse;
    Particule* particule;
    Boite* fille;
    Boite* soeur;

  public:
    Boite(int niv,double x,double y,double masse_x, double masse_y,double masse, Particule* part);
    ~Boite();

};

creation
#endif //BOITE_HPP
