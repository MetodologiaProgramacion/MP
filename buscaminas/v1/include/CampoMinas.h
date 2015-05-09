#ifndef CAMPO_MINAS_H
#define CAMPO_MINAS_H

#include <cstdlib>
#include <assert.h>
#include "tablero.h"

using namespace std;

class CampoMinas{
protected:
	Tablero tablero;

	void PrintCelda(int fila, int columna);
	void PrintCeldaAbierta(int fila, int columna);
	int NumMinasCerca(int fila, int columna);
	void AbrirEntorno(int fila, int columna);
	void AbrirTodas();

public:
	CampoMinas(int f, int c, int n_minas);
	int Filas();
	int Columnas();
	bool Explosion();
	bool Victoria();
	bool Marcar(int fila, int columna);
	bool Abrir(int fila, int columna);
	void PrettyPrint();
	bool TableroFin();
};

#endif