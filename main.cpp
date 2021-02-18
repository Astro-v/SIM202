#include <iostream>
#include "Boite.hpp"
#include "Particule.hpp"
#include <stdlib.h>
#include <cmath>
#include "MyWindow.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
  N_part = 10;
  Boite principale = Boite(0,0.5,0.5,0, 0,0, 1);

  for(int i = 0; i < Nb_part; i++){
    //Génération des conditions initiales
    double X1=rand()/(double)RAND_MAX;
    class Particule P;
    double r=pow(0.999*pow(X1,-2.0/3.0)-1,-1.0/2.0);
    double X2=rand()/(double)RAND_MAX;
    double X3=rand()/(double)RAND_MAX;
    double u=sqrt(pow(X2,2)+pow(X3,2));
    while (u>1){
        X2=rand()/(double)RAND_MAX;
        X3=rand()/(double)RAND_MAX;
        u=sqrt(pow(X2,2)+pow(X3,2));
    }
    P.x=r*X2/u;
    P.y=r*X3/u;
    //Méthode de rejet pour déterminer q
    double X5=rand()/(double)RAND_MAX;
    double X6=rand()/(double)RAND_MAX;
    double g=pow(X5,2)*pow(1-pow(X5,2),7.0/2.0);
    while (X6>10*g){
        X5=rand()/(double)RAND_MAX;
        X6=rand()/(double)RAND_MAX;
        g=pow(X5,2)*pow(1-pow(X5,2),7.0/2.0);
    }
    double q=X5;
    double v=vitesse_echappement(P,q);
    double X7=rand()/(double)RAND_MAX;
    double X8=rand()/(double)RAND_MAX;
    double uv=sqrt(pow(X7,2)+pow(X8,2));
    while (uv>1){
        X7=rand()/(double)RAND_MAX;
        X8=rand()/(double)RAND_MAX;
        uv=sqrt(pow(X7,2)+pow(X8,2));
    }
    P.vx=v*X7/uv;
    P.vy=v*X8/uv;
    P.m=1/N_part;
    principale.insert(P);
  }
    MyWindow window(1000,1000);
    while (window.isOpen())
    {
         sf::Event event;
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
              {
                  window.close();
              }
          }

          calcul(&principale);
    }

  return 0;
}

void calcul(Boite* b){
  if(b == NULL){
    return;
  }

  for(int i = 0; i < particules.size(); i++){ //Pour chaque particule de la boite
    //On calcule la résultante des forces qui s'applique sur la particule
    double f = calcul_force()
    //On met à jour la vitesse et la position de la particule
  }

  //On appelle recursivement calcul sur les filles de b
  calcul(b->nordOuest);
  calcul(b->sudOuest);
  calcul(b->nordEst);
  calcul(b->sudEst);

}
