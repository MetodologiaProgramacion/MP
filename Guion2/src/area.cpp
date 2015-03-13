#include <iostream>
#include <cmath> 
#include "circulo.h"
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
	Circulo c;
	double area;

	cout << "Introduzca un circulo en formato radio-(x,y): ";
	Avanzar(cin);
	LeerC(cin,c);
	area = Area(c);
	cout << "\nEl área del círculo vale " << area << endl;
}