#include "tablero.h"
using namespace std;

// Implementación clase Casilla
Casilla::Casilla(){
	estado = CERRADA;
	contenido = VACIA;
};

void Casilla::abrir(){
	if (estado != MARCADA){
		estado = ABIERTA;
	}
}

void Casilla::cerrar(){
	estado = CERRADA;
}

void Casilla::marcar(){
	if (estado == CERRADA){
		estado = MARCADA;
	} else if(estado == MARCADA){
		estado = CERRADA;
	}
}

EstadoCasilla Casilla::get_estado(){
	return estado;
}

void Casilla::set_contenido(ContenidoCasilla c){
	contenido = c;
}

ContenidoCasilla Casilla::get_contenido(){
	return contenido;
}

ostream& operator<<(ostream& os, Casilla casilla){
	switch (casilla.get_estado()){
		case CERRADA: os << "*";break;
		case MARCADA: os << "?";break;
		case ABIERTA: os << " ";break;
		//default: os.setState(ios::failbit);
	}

	switch (casilla.get_contenido()){
		case VACIA: os << "0|";break;
		case MINA: os << "1|";break;
		//default: os.setState(ios::failbit);
	}

	return os;
}

istream& operator>>(istream& is, Casilla& casilla){
	while (is.peek() == '\n')
		is.ignore();

	switch(is.peek()){
		case '*': casilla.cerrar();break;
		case '?': casilla.marcar();break;
		case ' ': casilla.abrir();break;
		//default: is.setState(ios::failbit);
	}
	is.ignore();
	switch(is.peek()){
		case '0': casilla.set_contenido(VACIA);break;
		case '1': casilla.set_contenido(MINA);break;
		//default: is.setState(ios::failbit);
	}
	is.ignore();
	// saltamos '|'
	is.ignore();

	return is;
}




// Implementación clase Tablero

Tablero::Tablero(int f, int c){
	filas = f;
	columnas = c;
	tablero = new Casilla[f*c];	
}

Tablero::Tablero(const Tablero& t){
	this->filas = t.filas;
	this->columnas = t.columnas;
	this->tablero = new Casilla[filas * columnas];

	for (int i=0; i < filas*columnas; i++){
		this->tablero[i] = t.tablero[i];
	}
	
}

Tablero::~Tablero(){
	delete[] tablero;
}

int Tablero::get_filas(){
	return filas;
}

int Tablero::get_columnas(){
	return columnas;
}

EstadoCasilla Tablero::get_estado_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	return tablero[f*get_columnas() + c].get_estado();
}

void Tablero::abrir_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	tablero[f*get_columnas() + c].abrir();
}

void Tablero::marcar_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	tablero[f*get_columnas() + c].marcar();
}

ContenidoCasilla Tablero::get_contenido_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	return tablero[f*get_columnas() + c].get_contenido();
}

void Tablero::poner_mina(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	tablero[f*get_columnas() + c].set_contenido(MINA);
}

Tablero& Tablero::operator=(const Tablero& t){
	if (&t != this){
		this->filas = t.filas;
		this->columnas = t.columnas;
		delete[] tablero;
		this->tablero = new Casilla[filas*columnas];

		for (int i=0; i < filas*columnas; i++){
			this->tablero[i] = t.tablero[i];
		}
	}

	return *this;
}

Casilla& Tablero::operator()(int fila, int columna){
	return tablero[fila*get_columnas() + columna];
}

ostream& operator<<(ostream& os, Tablero& tablero){
	int filas = tablero.get_filas();
	int columnas = tablero.get_columnas();

	os << filas << 'X' << columnas << endl;
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			os << tablero(i, j);
		}
		os << endl;
	}

	return os;
}

istream& operator>>(istream& is, Tablero& tablero){
	is >> tablero.filas;
	is.ignore();
	is >> tablero.columnas;

	for (int i=0; i<tablero.filas; i++){
		for (int j=0; j<tablero.columnas; j++){
			is >> tablero.tablero[i*tablero.columnas + j];
		}
		is.ignore();
	}

	return is;
}