#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_

#include "punto.h"

struct Rectangulo{
	Punto inf_izquierda;
	Punto sup_derecha;
};

void InicializarRectangulo(Rectangulo &rectangulo, const Punto &inf_i, const Punto &sup_d);
Punto sup_izquierda(Rectangulo rectangulo);
Punto inf_derecha(Rectangulo rectangulo);
double Area(const Rectangulo &rectangulo);
bool Interior(const Punto &p, const Rectangulo &r);
void EscribirRectangulo(Rectangulo rectangulo);

#endif