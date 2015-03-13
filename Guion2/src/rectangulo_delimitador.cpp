#include <iostream>
#include "punto.h"
#include "rectangulo.h"
using namespace std;


int leer_puntos(Punto*, int, istream&);
void avanzar(istream& is);
double min_x(Punto* puntos, int numero_puntos);
double max_x(Punto* puntos, int numero_puntos);
double min_y(Punto* puntos, int numero_puntos);
double max_y(Punto* puntos, int numero_puntos);


int main(){
	Rectangulo rectangulo_del;
	const int MAX = 100;
	Punto puntos[MAX];
	Punto inf_i;
	Punto sup_d;
	int numero_puntos;

	numero_puntos = leer_puntos(puntos, MAX, cin);

	if (numero_puntos == 1){
		inf_i = puntos[0];
		sup_d = puntos[0];
	} else if (numero_puntos == 2){
		inf_i = puntos[0];
		sup_d = puntos[1];
	} else if (numero_puntos > 2){
		InicializarPunto(inf_i, min_x(puntos, numero_puntos), min_y(puntos, numero_puntos));
		InicializarPunto(sup_d, max_x(puntos, numero_puntos), max_y(puntos, numero_puntos));
	} else {
		InicializarPunto(inf_i, 0.0, 0.0);
		InicializarPunto(sup_d, 0.0, 0.0);
	}

	InicializarRectangulo(rectangulo_del, inf_i, sup_d);
	EscribirRectangulo(rectangulo_del);
}

int leer_puntos(Punto* p, const int MAX, istream &is){
	bool correcto = true;
	int i=0;

	for (i; i < MAX && correcto; i++){
		avanzar(is);
		correcto = Leer(is, p[i]);
	}

	return i-1;
}

void avanzar(istream& is){
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n');
    else is.ignore();
  }
}

double min_x(Punto* puntos, int numero_puntos){
	double min_x;

	min_x = puntos[0].x;
	for (int i = 1; i < numero_puntos; i++){
		if (puntos[i].x < min_x){
			min_x = puntos[i].x;
		}
	}

	return min_x;
}

double min_y(Punto* puntos, int numero_puntos){
	double min_y;

	min_y = puntos[0].y;
	for (int i = 1; i < numero_puntos; i++){
		if (puntos[i].y < min_y){
			min_y = puntos[i].y;
		}
	}

	return min_y;
}

double max_x(Punto* puntos, int numero_puntos){
	double max_x;

	max_x = puntos[0].x;
	for (int i = 1; i < numero_puntos; i++){
		if (puntos[i].x > max_x){
			max_x = puntos[i].x;
		}
	}

	return max_x;
}

double max_y(Punto* puntos, int numero_puntos){
	double max_y;

	max_y = puntos[0].y;
	for (int i = 1; i < numero_puntos; i++){
		if (puntos[i].y > max_y){
			max_y = puntos[i].y;
		}
	}

	return max_y;
}