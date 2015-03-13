#include <iostream>
#include <fstream>
#include <cmath> // sqrt, M_PI
#include "punto.h"

using namespace std;

bool LeerP(istream& is, Punto& p){
  if (is.peek() == '('){
    is.ignore();
    if (is >> p.x){
      if (is.peek() == ','){
        is.ignore();
        if (is >> p.y){
          if (is.peek() == ')'){
            is.ignore();
            return true;
          }
        }
      }
    }
  }
  return false;
}
bool EscribirP(ostream& os, const Punto& p){
  if (os << '(' << p.x << ',' << p.y << ')')
    return true;

  return false;

}
// FIXME: Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
void LeerPunto(Punto& p)
{
  char c;
  cin >> c;
  cin >> p.x;
  cin >> c;
  cin >> p.y;
  cin >> c;
}

// FIXME: Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (const Punto& p)
{
  cout << '(' << p.x << ',' << p.y << ')';
}

// FIXME: Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto& p, double cx, double cy)
{
  p.x = cx;
  p.y = cy;
}

// FIXME: Devuelve la coordenada X del punto p
double GetX (const Punto& p)
{
  return p.x;
}

// FIXME: Devuelve la coordenada Y del punto p
double GetY (const Punto& p)
{
  return p.y;
}

// FIXME: Devuelve la distancia euclídea entre p1 y p2
double Distancia (const Punto& p1, const Punto& p2)
{
  double distancia, dif_x, dif_y;
  dif_x = p1.x - p2.x;
  dif_y = p1.y - p2.y;
  distancia = sqrt(dif_x*dif_x + dif_y*dif_y);
  return distancia;
}

// FIXME: Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (const Punto& p1, const Punto& p2)
{
  Punto punto_medio;
  punto_medio.x = (p1.x + p2.x)/2;
  punto_medio.y = (p1.y + p2.y)/2;
  return punto_medio;
}