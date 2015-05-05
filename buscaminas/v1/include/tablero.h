#ifndef TABLERO_H
#define TABLERO_H

enum EstadoCasilla {CERRADA, ABIERTA, MARCADA};
enum ContenidoCasilla {VACIA, MINA};

class Casilla{
private:
	EstadoCasilla estado;
	ContenidoCasilla contenido;

public:
	Casilla();
	void abrir();
	void cerrar();
	void marcar();
	EstadoCasilla get_estado();
	void set_contenido(ContenidoCasilla c);
	ContenidoCasilla get_contenido();
};

class Tablero{
private:
	static const int MAX_FILAS = 20;
	static const int MAX_COLUMNAS = 20;
	Casilla tablero[MAX_FILAS][MAX_COLUMNAS];
	int filas;
	int columnas;

public:
	Tablero(int f, int c);
	int get_filas();
	int get_columnas();
	EstadoCasilla get_estado_casilla(int f, int c);
	void abrir_casilla(int f, int c);
	void marcar_casilla(int f, int c);
	ContenidoCasilla get_contenido_casilla(int f, int c);
	void poner_mina(int f, int c);
};

#endif
