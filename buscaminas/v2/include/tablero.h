/**
  * @file tablero.h
  * @brief Fichero cabecera para la clase tablero
  *
  * Contiene las operaciones para controlar un tablero de buscaminas
  *
  */

#ifndef TABLERO_H
#define TABLERO_H

#include <cstdlib>
#include <assert.h>

/**
  * @brief Estado de una casilla
  *
  * Posibles estados en los que se puede encontrar una casilla
  *
  */
enum EstadoCasilla {CERRADA, ABIERTA, MARCADA};

/**
  * @brief Contenido de una casilla
  *
  * Posibles contenidos en una casilla
  *
  */
enum ContenidoCasilla {VACIA, MINA};


/**
  * @brief Clase Casilla
  *
  * Clase utilizada para representar las casillas del tablero
  *
  */
class Casilla{
private:
	EstadoCasilla estado;
	ContenidoCasilla contenido;

public:
	/**
  	  * @brief Inicializa la casilla como CERRADA y VACIA
  	  *
  	  * @see EstadoCasilla
  	  * @see ContenidoCasilla
    */
	Casilla();

	/**
  	  * @brief Cambia el estado de la casilla a ABIERTA
  	  *
  	  *	@pre la casilla no puede estar MARCADA
  	  *
  	  * @see EstadoCasilla
    */
	void abrir();

	/**
  	  * @brief Cambia el estado de la casilla a CERRADA
  	  *
  	  * @see EstadoCasilla
    */
	void cerrar();

	/**
  	  * @brief Cambia el estado de la casilla a MARCADA (o a CERRADA si ya estaba en MARCADA)
  	  *
  	  * @pre la casilla no puede estar ABIERTA
  	  *
  	  * @see EstadoCasilla
    */
	void marcar();

	/**
  	  * @brief Devuelve el estado de la casilla
  	  *
  	  * @return El estado de la casilla
  	  *
  	  * @see EstadoCasilla
    */
	EstadoCasilla get_estado();

	/**
  	  * @brief Establece el contenido de la casilla
  	  *
  	  * @param contenido contenido que se quiere establecer
  	  *
  	  * @see ContenidoCasilla
    */
	void set_contenido(ContenidoCasilla contenido);

	/**
  	  * @brief Devuelve el contenido de la casilla
  	  *
  	  * @return El contenido de la casilla
  	  *
  	  * @see ContenidoCasilla
    */
	ContenidoCasilla get_contenido();
};


/**
  * @brief Clase Tablero
  *
  * Clase utilizada para representar un tablero de buscaminas
  *
  * @see Casilla
  */
class Tablero{
private:
	Casilla *tablero;
	int filas;
	int columnas;

public:
	/**
  	  * @brief Inicializa el tablero
  	  *
  	  * @param filas filas del tablero
  	  * @param columnas columnas del tablero
  	  *
  	  * @pre el número de filas debe ser menor o igual a 20
  	  * @pre el número de columnas debe ser menor o igual a 20
    */
	Tablero(int filas, int columnas);
	
	/**
	  * @brief Inicializa el tablero a partir de otro
	  *
	  * @param tablero El tablero a copiar
	  */
	Tablero(const Tablero& tablero);

	/**
	  * @brief Destructor de el tablero
	  */
	~Tablero();

	/**
  	  * @brief Devuelve el número de filas del tablero
  	  *
  	  * @return las filas del tablero
    */
	int get_filas();

	/**
  	  * @brief Devuelve el número de columnas del tablero
  	  *
  	  * @return las columnas del tablero
    */
	int get_columnas();

	/**
  	  * @brief Devuelve el estado de una casilla
  	  *
  	  * @param fila fila donde se encuentra la casilla
  	  * @param columna columna donde se encuentra la casilla
  	  *
  	  * @return el estado de la casilla
  	  * @see EstadoCasilla
    */
	EstadoCasilla get_estado_casilla(int fila, int columna);

	/**
  	  * @brief Establece una casilla como abierta
  	  *
  	  * @param fila fila donde se encuentra la casilla
  	  * @param columna columna donde se encuentra la casilla
  	  *
  	  * @see EstadoCasilla
    */
	void abrir_casilla(int fila, int columna);

	/**
  	  * @brief Establece una casilla como marcada (o la desmarca si ya estaba marcada)
  	  *
  	  * @param fila fila donde se encuentra la casilla
  	  * @param columna columna donde se encuentra la casilla
  	  *
  	  * @pre la casilla debe estar cerrada
  	  *
  	  * @see EstadoCasilla
    */
	void marcar_casilla(int fila, int columna);

	/**
  	  * @brief Devuelve el contenido de una casilla
  	  *
  	  * @param fila fila donde se encuentra la casilla
  	  * @param columna columna donde se encuentra la casilla
  	  *
  	  * @return el contenido de la casilla
  	  * @see ContenidoCasilla
    */
	ContenidoCasilla get_contenido_casilla(int fila, int columna);

	/**
  	  * @brief Establece una mina como contenido de una casilla
  	  *
  	  * @param fila fila donde se encuentra la casilla
  	  * @param columna columna donde se encuentra la casilla
  	  *
  	  * @see ContenidoCasilla
    */
	void poner_mina(int fila, int columna);
	
	/**
  	  * @brief Operador = de la clase tablero
  	  *
  	  * @param tablero Tablero desde donde se copian los datos
    	  */
	Tablero& operator=(const Tablero& tablero);
};

#endif
