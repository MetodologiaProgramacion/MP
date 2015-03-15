#include <iostream>
#include <cmath> // sqrt, M_PI
#include "circulo.h"
#include "punto.h"

using namespace std;

int main()
{
  Circulo c1,c2;

  do {
   cout << "Introduzca un circulo en formato radio-(x,y): ";
   LeerC(cin,c1);
   cout << "Introduzca otro circulo: ";
   LeerC(cin,c2);
  } while (Distancia(Centro(c1),Centro(c2))==0);

  Circulo res;

  InicializarCirculo(res,PuntoMedio(Centro(c1),Centro(c2)),
                     Distancia(Centro(c1),Centro(c2))/2);
  cout << "El círculo que pasa por los dos centros es: ";
  EscribirC(cout,res);
  cout << endl;
}