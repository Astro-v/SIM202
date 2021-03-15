// g++ -ID:/SFML/include -o out .\main.cpp .\Constant.hpp .\MyWindow.cpp .\Particule.cpp .\Boite.cpp -LD:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

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
#include "Constant.hpp"
#include "MyWindow.hpp"


using namespace std;

void displayBox(Boite&,MyWindow&);
void euler(vector<Particule>&);
void euler_quad(vector<Particule>& P, Boite principale, double theta);
void createGalaxy(vector<Particule>& vecPart, double rmin, double rmax, int N_part, double massetot, double x = 0.5, double y = 0.5, double vx = 0, double vy = 0);
void createGalaxy_initial(vector<Particule>& vecPart, int N_part);

int main()
{

    int N_part1 =1;
    int N_part2 = 0;
    int N_part = N_part1+N_part2;
    Boite principale = Boite(1,0.5,0.5,0, 0,0, 1);
    vector<Particule> vecPart;
    //createGalaxy(vecPart,0.001,0.05,N_part1,1);
    //createGalaxy(vecPart,0.0005,0.02,N_part2,1.0/N_part,0.7,0.7,-0.03,0);
    //createGalaxy_initial(vecPart,N_part);
    Particule P;
    P.x = rand()/(double)RAND_MAX - 0.5;
    P.y = rand()/(double)RAND_MAX - 0.5;

    vecPart.push_back(P);
    int count(0);
    MyWindow window(SIZE,SIZE);
    while (window.isOpen())
    {   count++;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // We compute next step
        //euler(vecPart);
        //euler_quad(vecPart, principale,0.7);

        if(count%500 == 0){
          Particule P;
          P.x = rand()/(double)RAND_MAX;
          P.y = rand()/(double)RAND_MAX;
          cout<<P.x<<P.y<<endl;

          vecPart.push_back(P);
          N_part++;
        }

        window.clear();


        principale.nouveau();
        for (int i(0);i<N_part;++i)
        {
            principale.insert(&vecPart[i]);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
              //Si on appuie sur espace, on affiche les boites
              displayBox(principale,window);
        }
        displayBox(principale,window);

        for (int i(0);i<N_part;++i)
        {
            window.drawParticle(vecPart[i].x*SIZE,vecPart[i].y*SIZE,4);

        }

        window.display();

    }
    system("PAUSE");
    return 0;
}


void createGalaxy(vector<Particule>& vecPart, double rmin, double rmax, int N_part, double massetot, double x, double y, double vx, double vy)
{
    int mult(12);

    for (int i(0);i<N_part;++i)
    {
        Particule P;
        double r=rmax*rand()/((double)RAND_MAX);
        double theta=rand()/(double)RAND_MAX;
        if (r>rmin)
        {
            P.x=r*cos(2*3.14*theta)+x;
            P.y=r*sin(2*3.14*theta)+y;
            P.vx = -pow(r,0.4)/mult*sin(2*3.14*theta)+vx;
            P.vy = pow(r,0.4)/mult*cos(2*3.14*theta)+vy;
        }
        else
        {
            P.x=rmin*cos(2*3.14*theta)+x;
            P.y=rmin*sin(2*3.14*theta)+y;
            P.vx = -pow(rmin,0.4)/mult*sin(2*3.14*theta)+vx;
            P.vy = pow(rmin,0.4)/mult*cos(2*3.14*theta)+vy;
        }

        P.m=massetot/N_part;
        vecPart.push_back(P);
    }
}

void createGalaxy_initial(vector<Particule>& vecPart, int N_part){
        //Génération des conditions initiales
      while(vecPart.size() < N_part){
        double X1=rand()/(double)RAND_MAX;
        Particule P;
        double r=pow(0.999*pow(X1,-2.0/3.0)-1,-1.0/2.0);
        double X2=rand()/(double)RAND_MAX-0.5;
        double X3=rand()/(double)RAND_MAX-0.5;
        double u=sqrt(pow(X2,2)+pow(X3,2));
        while (u>1){
            X2=rand()/(double)RAND_MAX-0.5;
            X3=rand()/(double)RAND_MAX-0.5;
            u=sqrt(pow(X2,2)+pow(X3,2));
        }

        P.x=r*X2/(10*u)+0.5;
        P.y=r*X3/(10*u)+0.5;
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
        double X7=rand()/(double)RAND_MAX-0.5;
        double X8=rand()/(double)RAND_MAX-0.5;
        double uv=sqrt(pow(X7,2)+pow(X8,2.));
        while (uv>1){
            X7=(rand()/(double)RAND_MAX-0.5);
            X8=(rand()/(double)RAND_MAX-0.5);
            uv=sqrt(pow(X7,2)+pow(X8,2.));
        }
        P.vx=v*X7/(10*uv);
        P.vy=v*X8/(10*uv);
        P.m=1/((double)N_part);
        P.vx=v*X7/(10*uv);
        P.vy=v*X8/(10*uv);
        P.m=1/((double)N_part);
        if  (P.x < 1 && P.y < 1)
        {
            vecPart.push_back(P);
        }
      }
    }

void displayBox(Boite& box,MyWindow& window)
{
    window.drawBox(box.getPos(1),box.getPos(2),box.getPos(0));
    if (box.getSubBox(0) != NULL){displayBox(*box.getSubBox(0),window);}
    if (box.getSubBox(1) != NULL){displayBox(*box.getSubBox(1),window);}
    if (box.getSubBox(2) != NULL){displayBox(*box.getSubBox(2),window);}
    if (box.getSubBox(3) != NULL){displayBox(*box.getSubBox(3),window);}
}

void euler(vector<Particule>& P)
{
    double dt(DT );
    int N_part(P.size());
    double forceX[N_part][N_part];
    double forceY[N_part][N_part];
    for (int i(0);i<N_part;++i)
    {
        for (int j(0);j<N_part;++j)
        {
            forceX[i][j] = 0;
            forceY[i][j] = 0;
            if (i!=j)
            {
                forceX[i][j] = force_interaction(P[j],P[i],0.01)*(P[i].x-P[j].x);
                forceY[i][j] = force_interaction(P[j],P[i],0.01)*(P[i].y-P[j].y);
            }

        }
    }
    for (int i(0);i<N_part;++i)
    {
        P[i].x = P[i].x + dt*P[i].vx;
        P[i].y = P[i].y + dt*P[i].vy;
        for (int j(0);j<N_part;++j)
        {
            P[i].vx = P[i].vx + dt*forceX[i][j];
            P[i].vy = P[i].vy + dt*forceY[i][j];
        }
    }
}

void euler_quad(vector<Particule>& P, Boite principale, double theta)
{
    double dt(DT);
    int N_part(P.size());
    for (int i(0);i<N_part;++i)
    {
        vector<double> force = principale.calcul_force(P[i], theta,0.01);

        P[i].x = P[i].x + dt*P[i].vx;
        P[i].y = P[i].y + dt*P[i].vy;

        P[i].vx = P[i].vx + dt*force[0];
        P[i].vy = P[i].vy + dt*force[1];
    }
}
