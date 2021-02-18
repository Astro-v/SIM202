// STANDART LIBRARY
#include <iostream> // Stream
#include <stdlib.h> 
#include <cmath>
#include <vector>

// GRAPHIC LIBRARY
#include <SFML/Graphics.hpp>

// INCLUDE LIBRARY
#include "Boite.hpp"
#include "Particule.hpp"
<<<<<<< HEAD
#include <stdlib.h>
#include <cmath>
//#include "MyWindow.hpp"
//#include <SFML/Graphics.hpp>
using namespace std;

Boite principale = Boite(1,0.5,0.5,0, 0,0, 1);

int main()
{
  int Nb_part = 10;
  vector<Particule> vecPart;

  for(int i = 0; i < Nb_part; i++){
    //Génération des conditions initiales
    /*
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
    P.m=1/Nb_part;
    */
    Particule P;
    P.x = (rand()%100)/(double)100;
    P.y = (rand()%100)/(double)100;
    P.vx=(rand()%100)/(double)100;
    P.vy=(rand()%100)/(double)100;
    P.m=1/Nb_part;
    //cout<<"Particule P : (x,y) =  ("<<P.x<<","<<P.y<<")"<<endl;
    vecPart.push_back(P);
    principale.insert(&P);
  }
}
/*
    MyWindow window(1000,1000);
=======
#include "Constant.hpp"
#include "MyWindow.hpp"


using namespace std;

void displayBox(Boite&,MyWindow&);

int main()
{

    int N_part = 10;
    Boite principale = Boite(0,0.5,0.5,0, 0,0, 1);
    vector<Particule> vecPart;
    while (vecPart.size() < N_part){
        //Génération des conditions initiales
        double X1=rand()/(double)RAND_MAX;
        Particule P;
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
        P.m=1/(double)N_part;
        if  (P.x < 1 && P.y < 1)
        {
            vecPart.push_back(P);
            //principale.insert(&vecPart[vecPart.size()-1]);
        }
    }
    
    MyWindow window(SIZE,SIZE);
>>>>>>> c39b413f74999d5f56879d45412df32c71ed8f9c
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

        window.clear();
        displayBox(principale,window);
        window.drawBox(100,100,100);
        window.drawParticle(110,210,10);
        window.drawParticle(120,260,10);
        window.display();
    }
    system("PAUSE");
    return 0;
}

void displayBox(Boite& box,MyWindow& window)
{
    window.drawBox(box.getPos(1),box.getPos(2),box.getPos(0));
    if (box.getSubBox(0) != NULL){displayBox(*box.getSubBox(0),window);}
    if (box.getSubBox(1) != NULL){displayBox(*box.getSubBox(1),window);}
    if (box.getSubBox(2) != NULL){displayBox(*box.getSubBox(2),window);}
    if (box.getSubBox(3) != NULL){displayBox(*box.getSubBox(3),window);}
}

void calcul(Boite* b){
  if(b == NULL){
    return;
  }

  for(int i = 0; i < particules.size(); i++){ //Pour chaque particule de la boite
    //On calcule la résultante des forces qui s'applique sur la particule
    double f = calcul_force(particules[i]);
    //On met à jour la vitesse et la position de la particule
  }

  //On appelle recursivement calcul sur les filles de b
  calcul(b->nordOuest);
  calcul(b->sudOuest);
  calcul(b->nordEst);
  calcul(b->sudEst);

}

double calcul_force(Particule* p){


}
*/
