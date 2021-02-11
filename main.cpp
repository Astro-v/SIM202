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
    double X1=(rand()%100)/100;
    class Particule P;
    double r=pow(0.999*pow(X1,-2/3)-1,-1/2);
    double X2=(rand()%100)/100;
    double X3=(rand()%100)/100;
    double u=sqrt(pow(X2,2)+pow(X3,2));
    while (u>1){
        X2=(rand()%100)/100;
        X3=(rand()%100)/100;
        u=sqrt(pow(X2,2)+pow(X3,2));
    }
    P.x=r*X2/u;
    P.y=r*X3/u;
    //Méthode de rejet pour déterminer q
    double X5=(rand()%100)/100;
    double X6=(rand()%100)/100;
    double g=pow(X5,2)*pow(1-pow(X5,2),7/2);
    while (X6>10*g){
        X5=(rand()%100)/100;
        X6=(rand()%100)/100;
        g=pow(X5,2)*pow(1-pow(X5,2),7/2);
    }
    double q=X5;
    double v=vitesse_echappement(P,q);
    double X7=(rand()%100)/100;
    double X8=(rand()%100)/100;
    double uv=sqrt(pow(X7,2)+pow(X8,2));
    while (uv>1){
        X7=(rand()%100)/100;
        X8=(rand()%100)/100;
        uv=sqrt(pow(X7,2)+pow(X8,2));
    }
    P.vx=v*X7/uv;
    P.vy=v*X8/uv;
    
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
    }

  return 0;
}
