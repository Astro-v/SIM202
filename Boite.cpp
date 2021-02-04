#include "Boite.hpp"
#include <math.h>

Boite::Boite(int niv,double x,double y,double masse_x, double masse_y,double m, int capacity_){
  niveau = niv;
  centre_x = x;
  centre_y = y;
  centre_masse_x = masse_x;
  centre_masse_y = masse_y;
  masse = m;
  nb_particules = 0;
  particule = NULL;
  nordOuest = NULL;
  nordEst = NULL;
  sudOuest = NULL;
  sudEst = NULL;
  capacity = capacity_;
}

Boite::~Boite(){
  particule = NULL;
  nordOuest = NULL;
  nordEst = NULL;
  sudOuest = NULL;
  sudEst = NULL;
}


bool Boite::contient(Particule* part){ //La particule est-elle située dans cette boite ?
  return((part->x < centre_x + pow(2,niveau + 1)) && (part->x > centre_x + pow(2,niveau + 1)) && (part->y < centre_y + pow(2,niveau + 1)) && (part->y > centre_y - pow(2,niveau + 1)));
}

void Boite::insert(Particule* part){
  if(!contient(part)){
    return;
  }
  //La particule est située dans cette boite, on l'ajoute donc
  if(nb_particules < capacity){
    //On ajoute la particule dans cette Boite
    return;
  }else{
    if(nordOuest == NULL){
      subdivise();
    }
    nordOuest->insert(part);
    nordEst->insert(part);
    sudEst->insert(part);
    sudOuest->insert(part);

    return;

  }
}

void Boite::subdivise(){
  Boite nO = Boite(niveau + 1, centre_x - pow(2,niveau+1),centre_y + pow(2,niveau+1),0,0,0,1);
  Boite nE = Boite(niveau + 1, centre_x + pow(2,niveau+1),centre_y + pow(2,niveau+1),0,0,0,1);
  Boite sO = Boite(niveau + 1, centre_x - pow(2,niveau+1),centre_y - pow(2,niveau+1),0,0,0,1);
  Boite sE = Boite(niveau + 1, centre_x + pow(2,niveau+1),centre_y - pow(2,niveau+1),0,0,0,1);

  nordOuest = &nO;
  nordEst = &nE;
  sudEst = &sE;
  sudOuest = &sO;
  return;
}
