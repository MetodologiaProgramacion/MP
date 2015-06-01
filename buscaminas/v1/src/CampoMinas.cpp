#include "CampoMinas.h"
using namespace std;


// Implementación de la clase CampoMinas

struct CeldaPosicion{
	int fila;
	int columna;
	CeldaPosicion* sig;
};

CampoMinas::CampoMinas(int f, int c, int n_minas): tablero(f, c){
	int i=0;
	int n_minas_min = 5;
	int n_minas_max = 0.5 * f*c;
	int rand_fila;
	int rand_columna;
	srand(time(0));
	
	n_minas = n_minas < n_minas_min ? n_minas_min : n_minas;
	n_minas = n_minas > n_minas_max ? n_minas_max : n_minas;
	while (i < n_minas){
		rand_fila = rand()%f;
		rand_columna = rand()%c;
		if (tablero.get_contenido_casilla(rand_fila, rand_columna) == VACIA){
			tablero.poner_mina(rand_fila, rand_columna);
			i++;
		}
	}
}

int CampoMinas::Filas(){
	return tablero.get_filas();
}

int CampoMinas::Columnas(){
	return tablero.get_columnas();
}

bool CampoMinas::Explosion(){
	bool explosion = false;
	int filas = Filas();
	int columnas = Columnas();

	for (int i=0; i < filas && explosion == false; i++){
		for (int j=0; j < columnas && explosion == false; j++){
			explosion = (tablero.get_contenido_casilla(i, j) == MINA) && (tablero.get_estado_casilla(i, j) == ABIERTA);
		}
	}

	return explosion;
}

bool CampoMinas::Victoria(){
	bool victoria = true;
	int filas = Filas();
	int columnas = Columnas();

	for (int i=0; i < filas && victoria; i++){
		for (int j=0; j < columnas && victoria; j++){
			if (tablero.get_contenido_casilla(i, j) != MINA){
				victoria = victoria && (tablero.get_estado_casilla(i, j) == ABIERTA);
			}
		}
	}

	victoria = victoria && !Explosion();

	return victoria;
}

bool CampoMinas::Marcar(int fila, int columna){
	bool puede_marcarse;

	puede_marcarse = tablero.get_estado_casilla(fila, columna) != ABIERTA;
	if (puede_marcarse){
		tablero.marcar_casilla(fila, columna);
	}

	return puede_marcarse;
}

bool CampoMinas::Abrir(int fila, int columna){
	bool puede_abrirse;
	ContenidoCasilla contenido = tablero.get_contenido_casilla(fila, columna);
	puede_abrirse = tablero.get_estado_casilla(fila, columna) == CERRADA;
	if (puede_abrirse){
		tablero.abrir_casilla(fila, columna);
		if (contenido == VACIA && NumMinasCerca(fila, columna) == 0){
			AbrirEntorno(fila, columna);
		}
	}
	return puede_abrirse;
}

void CampoMinas::AbrirEntorno(int fila, int columna){
	// indices de los bucles que recorren el entorno
	int f=fila-1, c=columna-1;
	// valores en los que paran los bucles
	int p=fila+1, q=columna+1;

	// condiciones para cubrir los extremos y las esquinas
	if (fila == 0)
		f = fila;
	if (fila == Filas()-1)
		p = fila;
	if (columna == 0)
		c = columna;
	if (columna == Columnas()-1)
		q = columna;

	for (int i=f; i <= p; i++){
		for (int j=c; j <= q; j++){
			if (tablero.get_contenido_casilla(i, j) == VACIA)
				Abrir(i,j);
		}
	}
}

void CampoMinas::PrettyPrint(){
	int filas = Filas();
	int columnas = Columnas();

	//    0 1 2 3 4 5 6 7 8 9 ...
	cout << ' ' << ' ' << ' ';
	for (int j=0; j < columnas; j++){
		cout << ' ' << j << ' ';
	}
	cout << endl;

	//  ----------------------- ...
	cout << ' ' << ' ' << '-';
	for (int j=0; j < columnas; j++){
		cout << "---";
	}
	cout << endl;

	//n_fila | *| *| *| *| ...
	for (int i=0; i < filas; i++){
		cout << i << " |";
		for (int j=0; j < columnas; j++){
			cout << ' ';
			PrintCelda(i, j);
		}
		cout << endl;
	}

	//  ----------------------- ...
	cout << ' ' << ' ' << '-';
	for (int j=0; j < columnas; j++){
		cout << "---";
	}
	cout << endl;
}

bool CampoMinas::TableroFin(){
	bool puede_imprimirse = Victoria() || Explosion();
	int filas = Filas();
	int columnas = Columnas();

	if (puede_imprimirse){
		AbrirTodas();
		PrettyPrint();
	}

	return puede_imprimirse;
}

void CampoMinas::AbrirTodas(){
	int filas = Filas();
	int columnas = Columnas();

	for (int i=0; i < filas; i++){
		for (int j=0; j < columnas; j++){
			if (tablero.get_estado_casilla(i, j) == MARCADA)
				tablero.marcar_casilla(i, j);
			tablero.abrir_casilla(i, j);
		}
	}
}

void CampoMinas::PrintCelda(int fila, int columna){
	switch (tablero.get_estado_casilla(fila, columna)){
		case CERRADA: cout << "*|";break;
		case MARCADA: cout << "?|";break;
		case ABIERTA: PrintCeldaAbierta(fila, columna);
	}
}

void CampoMinas::PrintCeldaAbierta(int fila, int columna){
	ContenidoCasilla contenido = tablero.get_contenido_casilla(fila, columna);
	int n_minas_cerca = NumMinasCerca(fila, columna);

	if (contenido == MINA){
		cout << "X|";
	} else if (contenido == VACIA){
		if (n_minas_cerca == 0) cout << ' ' << ' ';
		else cout << n_minas_cerca << ' ';
	}
}

int CampoMinas::NumMinasCerca(int fila, int columna){
	int num_minas_cerca = 0;
	// indices de los bucles que recorren el entorno
	int f=fila-1, c=columna-1;
	// valores en los que paran los bucles
	int p=fila+1, q=columna+1;

	// condiciones para cubrir los extremos y las esquinas
	if (fila == 0)
		f = fila;
	if (fila == Filas()-1)
		p = fila;
	if (columna == 0)
		c = columna;
	if (columna == Columnas()-1)
		q = columna;

	for (int i=f; i <= p; i++){
		for (int j=c; j <= q; j++){
			if (tablero.get_contenido_casilla(i, j) == MINA)
				num_minas_cerca++;
		}
	}

	return num_minas_cerca;
}