#include <iostream>
#include "Particule.hpp"
#include <cmath>

using namespace std;

const float G=1;

Particule::Particule(){
    x=0;
    y=0;
    m=1;
    vx=1;
    vy=1;
    vz=1;
}

Particule::Particule(double X, double Y, double Vx, double Vy, double Vz, double M){
    x=X;
    y=Y;
    m=M;
    vx=Vx;
    vy=Vy;
    vz=Vz;
}

Particule::Particule(const Particule& P){
    x=P.x;
    y=P.y;
    vx=P.vx;
    vy=P.vy;
    vz=P.vz;
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

double vitesse_echappement(Particule& P,double q){
    double R=sqrt(pow(P.x,2)+pow(P.y,2));
    return(q*sqrt(2)*pow((1.0+pow(R,2)),(-1/4)));
}
