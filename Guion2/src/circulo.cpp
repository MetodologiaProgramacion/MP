#include <iostream>
#include <cmath> // sqrt, M_PI
#include "circulo.h"
#include "punto.h"

using namespace std;

bool LeerC(istream &is, Circulo &c){
  if (is >> c.radio){
    if (is.peek()=='-'){
      if (LeerP(is,c.centro)){
        return true;
      }
    }
  }
  return false;
}

bool EscribirC(ostream &os, const Circulo &c){
  if (os << c.radio << '-'){
    if (EscribirP(os,c.centro))
      return true;
  }
  return false;
}
// FIXME: Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
void LeerCirculo(Circulo &c)
{
  cin >> c.radio;
  cin.ignore();
  LeerPunto(c.centro);
}

// FIXME: Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(const Circulo &c)
{
  cout << c.radio << '-';
  EscribirPunto(c.centro);
}

// FIXME: Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, const Punto &centro, double radio)
{
  c.centro = centro;
  c.radio = radio;
}

// FIXME: Devuelve del centro de c
Punto Centro (const Circulo &c)
{
  return c.centro;
}

// FIXME: Devuelve el radio de c
double Radio (const Circulo &c)
{
  return c.radio;
}

// FIXME: Devuelve el área del círculo c
double Area (const Circulo &c)
{
  double area = M_PI * c.radio * c.radio;
  return area;
}

// FIXME: Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (const Punto &p, const Circulo &c)
{
  bool esta_dentro = Distancia(p, c.centro) < c.radio;
  return esta_dentro;
}

// FIXME: Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (const Circulo &c1, const Circulo &c2)
{
  double distancia = Distancia(c1.centro, c2.centro) - c1.radio - c2.radio;
  return distancia;
}