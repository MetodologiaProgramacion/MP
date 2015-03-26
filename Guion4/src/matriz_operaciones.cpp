#include <iostream>
#include <fstream>
#include <cstring>
#include "matriz_bit.h"
#include "matriz_operaciones.h"
using namespace std;


enum TipoEntrada{BINARIA_FC, BINARIA, CARACTER_FC, CARACTER, DESCONOCIDO};

void Avanzar(istream& is);
char bool_to_char(bool b);
int ColumnasIstream(istream& is);
int char_to_int(char caracter);
int FilasIstream(istream& is);
void IgnorarCabecera(istream& is);
bool LeerBinariaFc(istream& is, MatrizBit& m);
bool LeerBinaria(istream& is, MatrizBit& m);
bool LeerCaracterFc(istream& is, MatrizBit& m);
bool LeerCaracter(istream& is, MatrizBit& m);
bool LeerMatriz(istream& is, MatrizBit& m, int f, int c, char cero, char uno);
TipoEntrada LeerTipoEntrada(istream& is);
bool TieneFc(istream& is);


// ES -------------------------------------------------------------------------
// LECTURA --------------------------------------------------------------------
bool Leer (const char nombre[], MatrizBit &m){
	ifstream fichero(nombre);
	istream& stream = fichero;
	fichero.close();

	Leer(stream, m);
}

bool Leer(istream& is, MatrizBit& m){
	bool correcto = true;
	TipoEntrada tipo = LeerTipoEntrada(is);

	switch(tipo){
		case BINARIA_FC: correcto = LeerBinariaFc(is, m);break;
		case BINARIA: correcto = LeerBinaria(is, m);break;
		case CARACTER_FC: correcto = LeerCaracterFc(is, m);break;
		case CARACTER: correcto = LeerCaracter(is, m);break;
		case DESCONOCIDO: correcto = false;
	}

	return correcto;
}

bool LeerBinariaFc(istream& is, MatrizBit& m){
	bool correcto;
	int filas, columnas;

	Avanzar(is);
	filas = char_to_int(is.get());
	Avanzar(is);
	columnas = char_to_int(is.get());
	Avanzar(is);
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

bool LeerCaracterFc(istream& is, MatrizBit& m){
	bool correcto;
	int filas, columnas;

	Avanzar(is);
	filas = char_to_int(is.get());
	Avanzar(is);
	columnas = char_to_int(is.get());
	Avanzar(is);
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
	int longitud_fila = c*2;
	char* fila = new char [longitud_fila];

	for (int i=0; i < f; i++){
		is.get(fila, longitud_fila);
		for (int j=0; j < longitud_fila; j++){
			if (fila[j] == cero){
				Set(m, i, j, false);
			} else if (fila[j] == uno){
				Set(m, i, j, true);
			}
		}
	}

	delete[] fila;
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

TipoEntrada LeerTipoEntrada(istream& is){
	TipoEntrada tipo = DESCONOCIDO;

	if(TieneFc(is)){
		IgnorarCabecera(is);
		if(is.peek() == '0' || is.peek() == '1'){
			tipo = BINARIA_FC;
		} else if (is.peek() == 'X' || is.peek() == '.'){
			tipo = CARACTER_FC;
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

bool TieneFc(istream &is){
	bool tiene_fc = false;
	bool condicion1 = false;
	bool condicion2 = false;
	const int MAX_CABECERA = 20;
	char cabecera[MAX_CABECERA];
	char muestra[3];

	is.get(cabecera, MAX_CABECERA, '\n');
	is.ignore();
	is.get(muestra, 3);

	for (int i=0; cabecera[i] != EOF && tiene_fc == false; i++){
		condicion1 = condicion1 || (cabecera[i] >= '2' && cabecera[i] <='9');
		condicion2 = condicion2 || ((cabecera[i] >= '0' && cabecera[i] <='9') && (cabecera[i+1] >= '0' && cabecera[i+1] <='9'));
		tiene_fc = tiene_fc || (condicion1 || condicion2);
	}

	if (!tiene_fc){
		tiene_fc = (cabecera[0] == '1') &&
				   (cabecera[1] == ' ')	&&
				   (cabecera[2] == '1') &&
				   (muestra[0] == '1') &&
				   (muestra[1] == '\n' || muestra[1] == EOF);
	}
	is.seekg (0, is.beg);

	return tiene_fc;
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
			os << bool_to_char(Get(m, i, j));
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