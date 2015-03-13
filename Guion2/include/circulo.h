#ifndef _CIRCULO_H_
#define _CIRCULO_H_
#include <iostream>
#include <fstream>
#include "punto.h"

using namespace std;

struct Circulo {
    Punto centro;
    double radio;
};
bool LeerC(istream& is, Circulo& c);
bool EscribirC(ostream& os, const Circulo& c);
void LeerCirculo(Circulo& c);
void EscribirCirculo(const Circulo& c);
void InicializarCirculo (Circulo& c, const Punto& centro, double radio);
Punto Centro (const Circulo& c);
double Radio (const Circulo& c);
double Area (const Circulo& c);
bool Interior (const Punto& p, const Circulo& c);
double Distancia (const Circulo& c1, const Circulo& c2);

#endif