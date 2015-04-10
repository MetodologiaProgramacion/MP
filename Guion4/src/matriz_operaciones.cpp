#include <iostream>
#include <fstream>
#include <cstring>
#include "matriz_bit.h"
#include "matriz_operaciones.h"
using namespace std;

#define MAX_CABECERA 20
enum TipoEntrada{BINARIA_CABECERA, BINARIA, CARACTER_CABECERA, CARACTER, DESCONOCIDO};

void Avanzar(istream& is);
char bool_to_char(bool b);
void Cabecera(istream& is, char* cabecera);
int ColumnasCabecera(char* cabecera);
int ColumnasIstream(istream& is);
int char_to_int(char caracter);
int FilasCabecera(char* cabecera);
int FilasIstream(istream& is);
void IgnorarCabecera(istream& is);
bool LeerBinariaCabecera(istream& is, MatrizBit& m);
bool LeerBinaria(istream& is, MatrizBit& m);
bool LeerCaracterCabecera(istream& is, MatrizBit& m);
bool LeerCaracter(istream& is, MatrizBit& m);
bool LeerMatriz(istream& is, MatrizBit& m, int f, int c, char cero, char uno);
TipoEntrada LeerTipoEntrada(istream& is);
bool TieneCabecera(istream& is);


// ES -------------------------------------------------------------------------
// LECTURA --------------------------------------------------------------------
bool Leer (const char nombre[], MatrizBit &m){
	bool correcto;
	ifstream fichero(nombre);

	correcto = Leer(fichero, m);
	fichero.close();

	return correcto;
}

bool Leer(istream& is, MatrizBit& m){
	bool correcto = true;
	TipoEntrada tipo = LeerTipoEntrada(is);

	switch(tipo){
		case BINARIA_CABECERA: correcto = LeerBinariaCabecera(is, m);break;
		case BINARIA: correcto = LeerBinaria(is, m);break;
		case CARACTER_CABECERA: correcto = LeerCaracterCabecera(is, m);break;
		case CARACTER: correcto = LeerCaracter(is, m);break;
		case DESCONOCIDO: correcto = false;
	}

	return correcto;
}

bool LeerBinariaCabecera(istream& is, MatrizBit& m){
	bool correcto;
	char cabecera[MAX_CABECERA];
	int filas, columnas;

	Cabecera(is, cabecera);
	filas = FilasCabecera(cabecera);
	columnas = ColumnasCabecera(cabecera);
	IgnorarCabecera(is);
	correcto = LeerMatriz(is, m, filas, columnas, '0', '1');

	return correcto;
}

bool LeerBinaria(istream& is, MatrizBit& m){
	bool correcto;
	int filas, columnas;

	filas = FilasIstream(is);
	columnas = ColumnasIstream(is);
	correcto = LeerMatriz(is, m, filas, columnas, '0', '1');

	return correcto;
}

bool LeerCaracterCabecera(istream& is, MatrizBit& m){
	bool correcto;
	char cabecera[MAX_CABECERA];
	int filas, columnas;

	Cabecera(is, cabecera);
	filas = FilasCabecera(cabecera);
	columnas = ColumnasCabecera(cabecera);
	IgnorarCabecera(is);
	correcto = LeerMatriz(is, m, filas, columnas, '.', 'X');

	return correcto;
}

bool LeerCaracter(istream& is, MatrizBit& m){
	bool correcto;
	int filas, columnas;

	filas = FilasIstream(is);
	columnas = ColumnasIstream(is);
	correcto = LeerMatriz(is, m, filas, columnas, '.', 'X');

	return correcto;
}

bool LeerMatriz(istream& is, MatrizBit& m, int f, int c, char cero, char uno){
	bool correcto = true;
	
	correcto = Inicializar(m, f, c);

	if (correcto){
		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				Avanzar(is);
					if (is.peek() == cero){
					Set(m, i, j, false);
				} else if (is.peek() == uno){
					Set(m, i, j, true);
				}
				is.ignore();
			}
		}
	}

	return correcto;
}

int FilasIstream(istream& is){
	int filas = 1;

	while (is.peek() != EOF){
		if (is.peek() == '\n'){
			filas++;
		}
		is.ignore();
	}
	is.seekg(0, is.beg);

	return filas;
}

int ColumnasIstream(istream& is){
	int columnas = 0;

	while (is.peek() != '\n' && is.peek() != EOF){
		if (!isspace(is.peek())){
			columnas++;
		}
		is.ignore();
	}
	is.seekg(0, is.beg);

	return columnas;
}

int FilasCabecera(char* cabecera){
	int filas = 0;
	int i=0;

	// Avanza los esacios del principio
	for (i; isspace(cabecera[i]); i++);
	// Obtiene las filas
	for (i; !isspace(cabecera[i]); i++){
		filas = filas*10 + char_to_int(cabecera[i]);
	}
	return filas;
}

int ColumnasCabecera(char* cabecera){
	int columnas = 0;
	int i=0;

	// Ignora los espacios del principio
	while (isspace(cabecera[i]))
		i++;
	// Ignora las filas
	while (!isspace(cabecera[i]))
		i++;
	// Ignora los espacios intermedios
	while (isspace(cabecera[i]))
		i++;
	// Obtiene las columnas
	for (i; cabecera[i] > '0' && cabecera[i] <= '9'; i++){
		columnas = (columnas*10) + char_to_int(cabecera[i]);
	}
	return columnas;
}

TipoEntrada LeerTipoEntrada(istream& is){
	TipoEntrada tipo = DESCONOCIDO;

	if(TieneCabecera(is)){
		IgnorarCabecera(is);
		if(is.peek() == '0' || is.peek() == '1'){
			tipo = BINARIA_CABECERA;
		} else if (is.peek() == 'X' || is.peek() == '.'){
			tipo = CARACTER_CABECERA;
		}
	} else {
		if(is.peek() == '0' || is.peek() == '1'){
			tipo = BINARIA;
		} else if (is.peek() == 'X' || is.peek() == '.'){
			tipo = CARACTER;
		}
	}
	is.seekg(0, is.beg);

	return tipo;
}

bool TieneCabecera(istream &is){
	bool tiene_cabecera = false;
	bool condicion1 = false;
	bool condicion2 = false;
	char cabecera[MAX_CABECERA];
	char muestra[4];

	Cabecera(is, cabecera);
	IgnorarCabecera(is);
	is.get(muestra, 4);
	cout << muestra << endl;

	for (int i=0; cabecera[i] != EOF && tiene_cabecera == false; i++){
		condicion1 = condicion1 || (cabecera[i] >= '2' && cabecera[i] <='9');
		condicion2 = condicion2 || ((cabecera[i] >= '0' && cabecera[i] <='9') && (cabecera[i+1] >= '0' && cabecera[i+1] <='9'));
		tiene_cabecera = tiene_cabecera || (condicion1 || condicion2);
	}

	if (!tiene_cabecera){
		tiene_cabecera = (cabecera[0] == '1') &&
				   (cabecera[1] == ' ')	&&
				   (cabecera[2] == '1') &&
				   (muestra[0] == '1') &&
				   (muestra[1] == '\n' || muestra[1] == EOF);
	}
	is.seekg (0, is.beg);

	return tiene_cabecera;
}

void Cabecera(istream& is, char* cabecera){
	is.get(cabecera, MAX_CABECERA - 1, '\n');
	cabecera[MAX_CABECERA - 1] = EOF;

	is.seekg (0, is.beg);
}

void IgnorarCabecera(istream& is){
	while(is.peek() != '\n')
		is.ignore();
	Avanzar(is);
}

void Avanzar(istream& is){
  while (isspace(is.peek()) || is.peek()=='\n'){
    is.ignore();
  }
}

int char_to_int(char caracter){
	return caracter - '0';
}

// Escritura---------------------------------------------------------------------
bool Escribir(const char nombre[], const MatrizBit& m){
	bool correcto;
	ofstream fichero(nombre);
	ostream& stream = fichero;
	fichero.close();

	correcto = Escribir(stream, m);

	return correcto;
}

bool Escribir(ostream& os, const MatrizBit& m){
	bool correcto = true;
	int filas = Filas(m);
	int columnas = Columnas(m);

	for (int i=0; i < filas; i++){
		for (int j=0; j < columnas; j++){
			os << Get(m, i, j);
			os << ' ';
		}
		os << endl;
	}
	os << endl;

	return correcto;
}

char bool_to_char(bool b){
	return (int)b + '0';
}

// Operaciones-----------------------------------------------------------------
bool And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
	int filas = Filas(m1);
	int columnas = Columnas(m1);

	if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2)) && Inicializar(res, filas, columnas)){
		for (int i=0; i < filas; i++){
			for (int j=0; j < columnas; j++){
				Set(res, i, j, Get(m1, i, j) && Get(m2, i, j));
			}
		}
		return true;
	}
	return false;
}

bool Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
	int filas = Filas(m1);
	int columnas = Columnas(m1);

	if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2)) && Inicializar(res, filas, columnas)){
		for (int i=0; i < filas; i++){
			for (int j=0; j < columnas; j++){
				Set(res, i, j, Get(m1, i, j) || Get(m2, i, j));
			}
		}
		return true;
	}
	return false;
}

bool Not(MatrizBit& res, const MatrizBit& m){
	int filas = Filas(m);
	int columnas = Columnas(m);

	if (Inicializar(res, filas, columnas)){
		for (int i=0; i < filas; i++){
			for (int j=0; j < columnas; j++){
				Set(res, i, j, !Get(m, i, j));
			}
		}
		return true;
	}
	return false;
}

bool Traspuesta(MatrizBit& res, const MatrizBit& m){
	int filas = Filas(m);
	int columnas = Columnas(m);

	if (Inicializar(res, filas, columnas)){
		for (int i=0; i < filas; i++){
			for (int j=0; j < columnas; i++){
				Set(res, j, i, Get(m, i, j));
			}
		}
		return true;
	}
	return false;
}