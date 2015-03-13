#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_

#include <iostream>
#include <fstream>
#include "punto.h"

struct Rectangulo{
	Punto inf_izquierda;
	Punto sup_derecha;
};


void InicializarRectangulo(Rectangulo& rectangulo, const Punto& inf_i, const Punto& sup_d);
Punto sup_izquierda(const Rectangulo& rectangulo);
Punto inf_derecha(const Rectangulo& rectangulo);
double Area(const Rectangulo& rectangulo);
bool Interior(const Punto& p, const Rectangulo& r);
void EscribirRectangulo(const Rectangulo& rectangulo);

#endif