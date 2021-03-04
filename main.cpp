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

int main()
{

    int N_part1 = 500;
    int N_part2 = 2000;
    int N_part = N_part1+N_part2;
    Boite principale = Boite(1,0.5,0.5,0, 0,0, 1);
    vector<Particule> vecPart;
    while (vecPart.size() < N_part1){
        /*
        //Génération des conditions initiales
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
        double uv=sqrt(pow(X7,2)+pow(X8,2));
        while (uv>1){
            X7=(rand()/(double)RAND_MAX-0.5);
            X8=(rand()/(double)RAND_MAX-0.5);
            uv=sqrt(pow(X7,2)+pow(X8,2));
        }
        P.vx=v*X7/(10*uv);
        P.vy=v*X8/(10*uv);
        P.m=1/((double)N_part);
        if  (P.x < 1 && P.y < 1)
        {
            vecPart.push_back(P);
            principale.insert(&vecPart[vecPart.size()-1]);
        }*/
        Particule P;
        double r=rand()/((double)RAND_MAX*16.0);
        double theta=rand()/(double)RAND_MAX;
        if (r>0.001)
        {
            P.x=r*cos(2*3.14*theta)+0.7;
            P.y=r*sin(2*3.14*theta)+0.7;
            P.vx = -sqrt(r)/20*sin(2*3.14*theta)-0.02;
            P.vy = sqrt(r)/20*cos(2*3.14*theta)-0.005;
        }
        else
        {
            P.x=0.05*cos(2*3.14*theta)+0.7;
            P.y=0.05*sin(2*3.14*theta)+0.7;
            P.vx = -sqrt(0.001)/20*sin(2*3.14*theta)-0.02;
            P.vy = sqrt(0.001)/20*cos(2*3.14*theta)-0.005;
        }

        P.m=1/((double)N_part);
        vecPart.push_back(P);
    }
    while (vecPart.size() < N_part1+N_part2){
  
        Particule P;
        double r=rand()/((double)RAND_MAX*8.0);
        double theta=rand()/(double)RAND_MAX;
        if (r>0.005)
        {
            P.x=r*cos(2*3.14*theta)+0.5;
            P.y=r*sin(2*3.14*theta)+0.5;
            P.vx = -sqrt(r)/20*sin(2*3.14*theta);
            P.vy = sqrt(r)/20*cos(2*3.14*theta);
        }
        else
        {
            P.x=0.05*cos(2*3.14*theta)+0.5;
            P.y=0.05*sin(2*3.14*theta)+0.5;
            P.vx = -sqrt(0.005)/20*sin(2*3.14*theta);
            P.vy = sqrt(0.005)/20*cos(2*3.14*theta);
        }

        P.m=1/((double)N_part);
        vecPart.push_back(P);
    }
    int count(100);
    MyWindow window(SIZE,SIZE);
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
        //cout<<"New step"<<endl;
        // We compute next step
        //euler(vecPart);
        euler_quad(vecPart, principale,0.7);
        //cout<<"On est sorti"<<endl;
        window.clear();

        //delete &principale;

        //Boite principale = Boite(1,0.5,0.5,0, 0,0, 1);
        principale.nouveau();

        for (int i(0);i<N_part;++i)
        {
            //window.drawParticle(vecPart[i].x*SIZE,vecPart[i].y*SIZE,4);
            principale.insert(&vecPart[i]);

        }
        //cout<<"On a recree les boites"<<endl;
        displayBox(principale,window);

        for (int i(0);i<N_part1+N_part2;++i)
        {
            window.drawParticle(vecPart[i].x*SIZE,vecPart[i].y*SIZE,1);

        }

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

void euler(vector<Particule>& P)
{
    double dt(0.0001);
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
    double dt(0.1);
    int N_part(P.size());
    for (int i(0);i<N_part;++i)
    {
        vector<double> force = principale.calcul_force(P[i], theta,0.01);

        //cout<<"On a calculé une force"<<endl;
        P[i].x = P[i].x + dt*P[i].vx;
        P[i].y = P[i].y + dt*P[i].vy;

        P[i].vx = P[i].vx + dt*force[0];
        P[i].vy = P[i].vy + dt*force[1];
    }
    //cout<<"TOUTES LES FORCES"<<endl;
}
