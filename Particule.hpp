<<<<<<< HEAD
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
=======
#include <iostream>
using namespace std;

#ifndef PARTICULE_H
#define PARTICULE_H

class Particule{
    public:
    double r,teta,v,m;
    Particule(); //Constructeur par défaut
    Particule(double r, double teta, double v, double m); //Constructeur à partir de variables
    Particule(const Particule& P); //Constructeur par copie 
};

double force_interaction(const Particule&, const Particule&);
double masse_isotrope()

#endif
>>>>>>> 0794415cf05d7a05364060cf082d931be2359eb3
