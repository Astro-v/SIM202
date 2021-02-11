#include <iostream>
#include "Particule.hpp"
#include <cmath>

using namespace std;

const float G=1;

Particule::Particule(){
    x=0;
    y=0;
    m=1;
    v=1;
}

Particule::Particule(double X, double Y, double V, double M){
    x=X;
    y=Y;
    m=M;
    v=V;
}

Particule::Particule(const Particule& P){
    x=P.x;
    y=P.y;
    v=P.v;
    m=P.m;
}

double force_interaction(const Particule& P, const Particule& Q,double eps){
    double R=fabs(sqrt(pow(P.x,2)+pow(P.y,2))-sqrt(pow(Q.x,2)+pow(Q.y,2)));
    if (R>eps){
        return((-G*P.m*Q.m)/(R*R));
    }
    else{
        return((-G*P.m*Q.m)/(eps*eps));
    }
}

void vitesse_echappement(Particule& P,double q){
    double R=sqrt(pow(P.x,2)+pow(P.y,2));
    P.v=q*sqrt(2)*pow((1.0+pow(R,2)),(-1/4));
}
