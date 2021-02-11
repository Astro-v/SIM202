#include <iostream>
using namespace std;

#ifndef PARTICULE_H
#define PARTICULE_H

class Particule{
    public:
    double x,y,vx,vy,vz,m;
    Particule(); //Constructeur par défaut
    Particule(double X, double Y, double Vx, double Vy, double Vz, double M); //Constructeur à partir de variables
    Particule(const Particule& P); //Constructeur par copie 
};

double force_interaction(const Particule&, const Particule&,double);
double vitesse_echappement(Particule&, double);

#endif
