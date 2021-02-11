#include <iostream>
#include "Particule.hpp"
#include <cmath>

using namespace std;

const float G=1;

Particule::Particule(){
    r=0;
    teta=0;
    m=1;
    v=1;
}

Particule::Particule(double R, double Teta, double V, double M){
    r=R;
    teta=Teta;
    m=M;
    v=V;
}

Particule::Particule(const Particule& P){
    r=P.r;
    teta=P.teta;
    v=P.v;
    m=P.m;
}

double force_interaction(const Particule& P, const Particule& Q,double eps){
    unsigned int R=P.r-Q.r;
    if (R>eps){
        return((-G*P.m*Q.m)/(R*R));
    }
    else{
        return((-G*P.m*Q.m)/(eps*eps));
    }
}

void vitesse_echappement(Particule& P,double q){
    P.v=q*sqrt(2)*(1+P.r^2)^(-1/4);
}
