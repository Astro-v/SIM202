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