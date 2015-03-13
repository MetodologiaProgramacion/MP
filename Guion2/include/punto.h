#ifndef _PUNTO_H_
#define _PUNTO_H_
#include <iostream>

using namespace std;

struct Punto {
    double x,y;
};
bool LeerP(istream &is, Punto $p);
bool EscribirP(ostream &os, const Punto &p);
void LeerPunto(Punto &p);
void EscribirPunto (const Punto &p);
void InicializarPunto (Punto &p, double cx, double cy);
double GetX (const Punto &p);
double GetY (const Punto &p);
double Distancia (const Punto &p1, const Punto &p2);
Punto PuntoMedio (const Punto &p1, const Punto &p2);

#endif