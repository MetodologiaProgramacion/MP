#include <iostream>
#include <cmath> 
#include "rectangulo.h"

void InicializarRectangulo(Rectangulo &rectangulo, const Punto &inf_i, const Punto &sup_d){

	rectangulo.inf_izquierda = inf_i;
	rectangulo.sup_derecha = sup_d;
}

Punto sup_izquierda(const Rectangulo &rectangulo){
	Punto sup_i;

	sup_i.x = rectangulo.inf_izquierda.x;
	sup_i.y = rectangulo.sup_derecha.y;

	return sup_i;
}

Punto inf_derecha(const Rectangulo &rectangulo){
	Punto inf_d;

	inf_d.x = rectangulo.sup_derecha.x;
	inf_d.y = rectangulo.inf_izquierda.y;

	return inf_d;
}

double Area(const Rectangulo &rectangulo){
	double area;
	Punto sup_izquierda = sup_izquierda(rectangulo);
	area = Distancia(sup_izquierda, rectangulo.sup_derecha) * Distancia(sup_izquierda, rectangulo.inf_izquierda);

	return area;
}

bool Interior(const Punto &p, const Rectangulo &r){
	return (p.x > r.inf_izquierda.x && p.x < r.sup_derecha.x) && (p.y > r.inf_izquierda.y && p.y < r.sup_derecha.y)
}

void EscribirRectangulo(const Rectangulo &rectangulo){
	cout << "Rectángulo:\n";
	EscribirPunto(sup_izquierda(rectangulo));
	EscribirPunto(rectangulo.sup_derecha);
	EscribirPunto(inf_derecha(rectangulo));
	EscribirPunto(rectangulo.inf_izquierda);
	cout << endl;
}