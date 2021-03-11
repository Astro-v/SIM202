#include "Boite.hpp"
#include "Constant.hpp"
#include <math.h>



Boite::Boite(int niv,double x,double y,double masse_x, double masse_y,double m, int capacity_){
  niveau = niv;
  centre_x = x;
  centre_y = y;
  centre_masse_x = masse_x;
  centre_masse_y = masse_y;
  masse = m;
  nb_particules = 0;
  nordOuest = NULL;
  nordEst = NULL;
  sudOuest = NULL;
  sudEst = NULL;
  capacity = capacity_;
}

Boite::~Boite(){
  delete nordOuest;
  delete nordEst;
  delete sudOuest;
  delete sudEst;
}


bool Boite::contient(Particule* part){ //La particule est-elle située dans cette boite ?
  return((part->x < centre_x + pow(2.,-(niveau))) && (part->x > centre_x - pow(2.,-(niveau))) && (part->y < centre_y + pow(2.,-(niveau))) && (part->y > centre_y - pow(2.,-(niveau))));
}

void Boite::insert(Particule* part){
  if(!contient(part)){
    return;
  }
  //La particule est située dans cette boite, on modifie donc le centre de masse et on l'ajoute.
  centre_masse_x = (masse*centre_masse_x +  part->m * part->x)/(masse + part->m);
  centre_masse_y = (masse*centre_masse_y +  part->m * part->y)/(masse + part->m);
  masse += part->m;
  if(nb_particules < capacity){

    //On ajoute la particule dans cette Boite
    particules.push_back(part);
    nb_particules += 1;

    return;
  }else{
    if(nordOuest == NULL){ //Si la boite n'a pas de fille
      subdivise(); //On crée les filles
    }

    nordOuest->insert(part); //On ajoute la particule dans ces filles
    nordEst->insert(part);
    sudEst->insert(part);
    sudOuest->insert(part);

    for(int i = 0; i < (int)particules.size();i++){
      nordOuest->insert(particules[i]); //On ajoute la particule dans ces filles
      nordEst->insert(particules[i]);
      sudEst->insert(particules[i]);
      sudOuest->insert(particules[i]);
      particules.clear();
    }
    return;

  }
}

void Boite::subdivise(){
  nordOuest = new Boite(niveau + 1, centre_x - pow(2.,-(niveau+1)),centre_y + pow(2.,-(niveau+1)),0,0,0,1);
  nordEst = new Boite(niveau + 1, centre_x + pow(2.,-(niveau+1)),centre_y + pow(2.,-(niveau+1)),0,0,0,1);;
  sudEst = new  Boite(niveau + 1, centre_x - pow(2.,-(niveau+1)),centre_y - pow(2.,-(niveau+1)),0,0,0,1);
  sudOuest = new Boite(niveau + 1, centre_x + pow(2.,-(niveau+1)),centre_y - pow(2.,-(niveau+1)),0,0,0,1);
  return;
}


vector<double> Boite::calcul_force(Particule P, double theta,double eps){
  vector<double> force;
  double r = sqrt(pow((P.x - centre_masse_x),2) + pow((P.y - centre_masse_y),2)); //Distance de P au centre de masse de la boite
  double d = pow(2.,-niveau + 1);
  if (d/r < theta){
    //On renvoit les forces exercées par le centre de masse de la boite
    if (r>eps){
        force.push_back((-GRAV*P.m*masse)/(r*r)*(P.x-centre_masse_x));
        force.push_back((-GRAV*P.m*masse)/(r*r)*(P.y-centre_masse_y));
        return force;
    }
    else{
      force.push_back((-GRAV*P.m*masse)/(eps*eps)*(P.x-centre_masse_x));
      force.push_back((-GRAV*P.m*masse)/(eps*eps)*(P.y-centre_masse_y));
      return force;
    }

  }else{
    if(nordOuest==NULL){
      //On renvoit les forces exercées par le centre de masse de la boite
      if (r>eps){
          force.push_back((-GRAV*P.m*masse)/(r*r)*(P.x-centre_masse_x));
          force.push_back((-GRAV*P.m*masse)/(r*r)*(P.y-centre_masse_y));
          return force;
      }
      else{
        force.push_back((-GRAV*P.m*masse)/(eps*eps)*(P.x-centre_masse_x));
        force.push_back((-GRAV*P.m*masse)/(eps*eps)*(P.y-centre_masse_y));
        return force;
      }
    }else{
      //on itère récursivement le processus
      vector<double> force_nO = nordOuest->calcul_force(P, theta, eps);
      vector<double> force_nE = nordEst->calcul_force(P, theta, eps);
      vector<double> force_sO = sudOuest->calcul_force(P, theta, eps);
      vector<double> force_sE = sudEst->calcul_force(P, theta, eps);
      force.push_back(force_nO[0] + force_nE[0] + force_sO[0] + force_sE[0]);
      force.push_back(force_nO[1] + force_nE[1] + force_sO[1] + force_sE[1]);
      return force;
    }
  }
}

void Boite::nouveau(){
  centre_masse_x = 0;
  centre_masse_y = 0;
  masse = 0;
  nb_particules = 0;
  nordOuest = NULL;
  nordEst = NULL;
  sudOuest = NULL;
  sudEst = NULL;
}

int Boite::getPos(int i)
/*
i = 0 : get size of the box
i = 1 : get posX of the box
i = 2 : get posY of the box
*/
{
  if (i==0)
  {
    return (int)floor(SIZE*pow(2,-niveau+1))-2;
  }
  else if (i==1)
  {
    return (int)floor(SIZE*centre_x - SIZE*pow(2,-niveau))+1;
  }
  else
  {
    return (int)floor(SIZE*centre_y - SIZE*pow(2,-niveau))+1;
  }
}

Boite* Boite::getSubBox(int i)
/*
    i = 0 : return nordOuest;
    i = 1 : return nordEst;
    i = 2 : return sudOuest;
    i = 3 : return sudEst;
*/
{
  switch (i)
  {
    case 0:
    return nordOuest;
    break;
    case 1:
    return nordEst;
    break;
    case 2:
    return sudOuest;
    break;
    case 3:
    return sudEst;
    break;
  }
}
