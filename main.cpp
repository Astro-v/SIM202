#include <iostream>
#include "Boite.hpp"
using namespace std;

int main()
{

  Particule p1 = Particule(0.25,0.75,1);
  Particule p2 = Particule(0.75,0.25,1);

  Boite principale = Boite(0,0.5,0.5,0, 0,0, 1);

  principale.insert(&p1);
  principale.insert(&p2);


  return 0;
}
