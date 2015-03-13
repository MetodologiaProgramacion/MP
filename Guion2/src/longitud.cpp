#include <iostream>
#include <cmath>
#include "punto.h"

using namespace std;

void Avanzar(istream &is){
	while (isspace(is.peek()) || is.peek()=='#'){
		if (is.peek()=='#')
			is.ignore(1024,'\n');
		else
			is.ignore();
	}
}

int main(){
	Punto a,b;
	double recorrido = 0;

	cout << "Introduzca los puntos en formato (x,y): ";
	Avanzar(cin);
	LeerP(cin,a);
	Avanzar(cin);

	while (LeerP(cin,b)){
		Avanzar(cin);
		recorrido += Distancia(a,b);
		a = b;
	}

	cout << "La longitud del recorrido es " << recorrido << endl;
}