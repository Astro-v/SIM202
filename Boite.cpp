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
  //cout<<"On insert une part"<<endl;
  //cout<<"On essaye dans la boite de centre "<<centre_x<<","<<centre_y<<endl;
  if(!contient(part)){
    //cout<<"Ce n'est pas la bonne boite"<<endl;
    return;
  }
  //La particule est située dans cette boite, on l'ajoute donc
  //cout<<"On a trouvé la bonne boite qui a deja "<<nb_particules<<" particules"<<endl;
  if(nb_particules < capacity){
    //cout<<"la Particule que l'on veut inserer est : (x,y) =  ("<<part->x<<","<<part->y<<")"<<endl;

    //On ajoute la particule dans cette Boite
    particules.push_back(part);
    //cout<<"On est la"<<endl;
    nb_particules += 1;
    //double x = (part->r)*cos(part->teta);
    //double y = (part->r)*sin(part->teta);
    centre_masse_x = (masse*centre_masse_x +  part->m * part->x)/(masse + part->m);
    centre_masse_y = (masse*centre_masse_y +  part->m * part->y)/(masse + part->m);
    masse += part->m;
    //cout<<"Ajouté"<<endl;
    return;
  }else{
    if(nordOuest == NULL){ //Si la boite n'a pas de fille
      //cout<<"On subdivise"<<endl;
      subdivise(); //On crée les filles
      //cout<<"Subdivisé"<<endl;
    }
    //cout<<"Boite nO : niveau : "<<niveau + 1<<" centre_x : "<<centre_x - pow(2.,-(niveau+1))<<" centre y : "<<centre_y + pow(2.,-(niveau+1))<<endl;

    nordOuest->insert(part); //On ajoute la particule dans ces filles
    nordEst->insert(part);
    sudEst->insert(part);
    sudOuest->insert(part);

    return;

  }
}

void Boite::subdivise(){

  //cout<<"Boite nO : niveau : "<<niveau + 1<<" centre_x : "<<centre_x - pow(2.,-(niveau+1))<<" centre y : "<<centre_y + pow(2.,-(niveau+1))<<endl;
  //Boite nO = Boite(niveau + 1, centre_x - pow(2.,-(niveau+1)),centre_y + pow(2.,-(niveau+1)),0,0,0,1);
  //cout<<"Boite nE : niveau : "<<niveau + 1<<" centre_x : "<<centre_x + pow(2.,-(niveau+1))<<" centre y : "<<centre_y + pow(2.,-(niveau+1))<<endl;
  //Boite nE = Boite(niveau + 1, centre_x + pow(2.,-(niveau+1)),centre_y + pow(2.,-(niveau+1)),0,0,0,1);
  //cout<<"Boite sO : niveau : "<<niveau + 1<<" centre_x : "<<centre_x - pow(2.,-(niveau+1))<<" centre y : "<<centre_y - pow(2.,-(niveau+1))<<endl;
  //Boite sO = Boite(niveau + 1, centre_x - pow(2.,-(niveau+1)),centre_y - pow(2.,-(niveau+1)),0,0,0,1);
  //cout<<"Boite sE : niveau : "<<niveau + 1<<" centre_x : "<<centre_x + pow(2.,-(niveau+1))<<" centre y : "<<centre_y - pow(2.,-(niveau+1))<<endl;
  //Boite sE = Boite(niveau + 1, centre_x + pow(2.,-(niveau+1)),centre_y - pow(2.,-(niveau+1)),0,0,0,1);


  nordOuest = new Boite(niveau + 1, centre_x - pow(2.,-(niveau+1)),centre_y + pow(2.,-(niveau+1)),0,0,0,1);
  nordEst = new Boite(niveau + 1, centre_x + pow(2.,-(niveau+1)),centre_y + pow(2.,-(niveau+1)),0,0,0,1);;
  sudEst = new  Boite(niveau + 1, centre_x - pow(2.,-(niveau+1)),centre_y - pow(2.,-(niveau+1)),0,0,0,1);
  sudOuest = new Boite(niveau + 1, centre_x + pow(2.,-(niveau+1)),centre_y - pow(2.,-(niveau+1)),0,0,0,1);
  return;
}
