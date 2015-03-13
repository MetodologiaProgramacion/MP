#include <iostream>
#include <fstream>
#include <cmath> 
#include "rectangulo.h"


void InicializarRectangulo(Rectangulo& rectangulo, const Punto& inf_i, const Punto& sup_d){

	rectangulo.inf_izquierda = inf_i;
	rectangulo.sup_derecha = sup_d;
}

Punto sup_izquierda(const Rectangulo& rectangulo){
	Punto sup_i;

	sup_i.x = rectangulo.inf_izquierda.x;
	sup_i.y = rectangulo.sup_derecha.y;

	return sup_i;
}

Punto inf_derecha(const Rectangulo& rectangulo){
	Punto inf_d;

	inf_d.x = rectangulo.sup_derecha.x;
	inf_d.y = rectangulo.inf_izquierda.y;

	return inf_d;
}

double Area(const Rectangulo& rectangulo){
	double area;
<<<<<<< HEAD
	Punto sup_iz = sup_izquierda(rectangulo);
=======
	Punto sup_iz;

	sup_iz = sup_izquierda(rectangulo);
>>>>>>> 605c5899efb3190aef295d39947f5579790e8a99
	area = Distancia(sup_iz, rectangulo.sup_derecha) * Distancia(sup_iz, rectangulo.inf_izquierda);

	return area;
}

<<<<<<< HEAD
bool Interior(const Punto& p, const Rectangulo& r){
=======
bool Interior(const Punto &p, const Rectangulo &r){
>>>>>>> 605c5899efb3190aef295d39947f5579790e8a99
	return (p.x > r.inf_izquierda.x && p.x < r.sup_derecha.x) && (p.y > r.inf_izquierda.y && p.y < r.sup_derecha.y);
}

void EscribirRectangulo(const Rectangulo& rectangulo){
	cout << "Rectángulo:\n";
<<<<<<< HEAD
	EscribirP(cout,sup_izquierda(rectangulo));
	EscribirP(cout,rectangulo.sup_derecha);
	EscribirP(cout,inf_derecha(rectangulo));
	EscribirP(cout,rectangulo.inf_izquierda);
=======
	EscribirP(cout, sup_izquierda(rectangulo));
	EscribirP(cout, rectangulo.sup_derecha);
	EscribirP(cout, inf_derecha(rectangulo));
	EscribirP(cout, rectangulo.inf_izquierda);
>>>>>>> 605c5899efb3190aef295d39947f5579790e8a99
	cout << endl;
}