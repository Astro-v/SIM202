#ifndef BOITE_HPP
#define BOITE_HPP


#include <iostream>
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
    Boite();
    ~Boite();




};

#endif //BOITE_HPP
