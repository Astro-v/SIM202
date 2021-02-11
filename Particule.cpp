#include <iostream>
#include "Particule.hpp"

using namespace std;

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