#include <cstdlib>
#include <assert.h>
#include "tablero.h"
using namespace std;

// Implementación clase Casilla
Casilla::Casilla(){
	estado = CERRADA;
	contenido = VACIA;
};

void Casilla::abrir(){
	estado = ABIERTA;
}

void Casilla::cerrar(){
	estado = CERRADA;
}

void Casilla::marcar(){
	estado = MARCADA;
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
	assert((f > 0 && f <= MAX_FILAS) && (c > 0 && c <= MAX_COLUMNAS));
	filas = f;
	columnas = c;	
}

int Tablero::get_filas(){
	return filas;
}

int Tablero::get_columnas(){
	return columnas;
}

EstadoCasilla Tablero::get_estado_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	return tablero[f][c].get_estado();
}

void Tablero::abrir_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	tablero[f][c].abrir();
}

void Tablero::marcar_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	tablero[f][c].marcar();
}

ContenidoCasilla Tablero::get_contenido_casilla(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	return tablero[f][c].get_contenido();
}

void Tablero::poner_mina(int f, int c){
	assert((f >= 0 && f <= filas) && (c >= 0 && c <= columnas));
	tablero[f][c].set_contenido(MINA);
}