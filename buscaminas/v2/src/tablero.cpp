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
