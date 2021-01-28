#include "Boite.hpp"

Boite::Boite(int niv,double x,double y,double masse_x, double masse_y,double m, Particule* part){
  niveau = niv;
  centre_x = x;
  centre_y = y;
  centre_masse_x = masse_x;
  centre_masse_y = masse_y;
  masse = m;
  particule = part;
  fille = NULL;
  soeur = NULL;
}

Boite::~Boite(){
  particule = NULL;
  fille = NULL;
  soeur = NULL;
}
