#include <iostream>
#include "tablero.h"
#include "CampoMinas.h"
using namespace std;


int main(int argc, char** argv){
	int filas, columnas, n_minas;
	int fils, cols;
	char accion;

	cout << "Dime el tamaño del tablero (filas y columnas): ";
	cin >> filas >> columnas;

	cout << "Dime el numero de minas: ";
	cin >> n_minas;

	CampoMinas campo(filas, columnas, n_minas);

	while(!campo.Victoria() && !campo.Explosion()){
		campo.PrettyPrint();
		cout << "Dime acción y posición (fil y col): ";
		cin >> accion >> fils >> cols;
		if (accion == 'a')
			campo.Abrir(fils, cols);
		else if (accion == 'm')
			campo.Marcar(fils, cols);
		else
			cout << "Acción no valida\n";
	}

	if (campo.Victoria())
		cout << "Has ganado\n";
	else
		cout << "Has perdido\n";

	campo.TableroFin();

	return 0;
}