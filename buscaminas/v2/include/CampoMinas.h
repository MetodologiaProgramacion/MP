/**
  * @file tablero.h
  * @brief Fichero cabecera para la clase CampoMinas
  *
  */

#ifndef CAMPO_MINAS_H
#define CAMPO_MINAS_H

#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <iostream>
#include "tablero.h"

using namespace std;


/**
  * @brief Clase CampoMinas
  * Inicializa y controla el campo de minas
  */
class CampoMinas{
protected:
	Tablero tablero;
  bool explosion;

	/**
  	  * @brief Imprime una celda en su estado actual
  	  *
  	  * @param fila Fila en la que se encuentra la casilla
  	  * @param columna Columna en la que se encuentra la casilla
    */
	void PrintCelda(int fila, int columna);

	/**
  	  * @brief Imprime una celda abierta en su estado actual
  	  *
  	  * @param fila Fila en la que se encuentra la casilla
  	  * @param columna Columna en la que se encuentra la casilla
    */
	void PrintCeldaAbierta(int fila, int columna);

	/**
  	  * @brief Devuelve elnumero de minas en el entorno de una celda
  	  *
  	  * @param fila Fila en la que se encuentra la casilla
  	  * @param columna Columna en la que se encuentra la casilla
  	  *
  	  * @return El numero de minas del entorno
    */
	int NumMinasCerca(int fila, int columna);

	/**
  	  * @brief Abre (si se puede) las casillas del entorno
  	  *
  	  * @param fila Fila en la que se encuentra la casilla
  	  * @param columna Columna en la que se encuentra la casilla
    */
	void AbrirEntorno(int fila, int columna);

	/**
  	  * @brief Abre forzosamente todas las casillas del tablero
    */
	void AbrirTodas();

public:
	/**
  	  * @brief Inicializa el tablero y coloca minas aleatoriamente
  	  *
  	  * @param filas Número de filas del tablero
  	  * @param columnas Número de columnas del tablero
  	  * @param n_minas Número de minas en el tablero
  	  *
  	  * @pre El número de minas debe ser mayor que 5
  	  * y no superar el 50% de casillas del tablero
    */
	CampoMinas(int filas, int columnas, int n_minas);

	/**
  	  * @brief Devuelve el numero de filas del tablero
  	  *
  	  * @return El numero de filas del tablero
    */
	int Filas();

	/**
  	  * @brief Devuelve el numero de columnas del tablero
  	  *
  	  * @return El numero de columnas del tablero
    */
	int Columnas();

	/**
  	  * @brief Comprueba si ha habido una explosión
  	  *
  	  * @return Un booleano que indica si ha habido una explosión
    */
	bool Explosion();

	/**
  	  * @brief Comprueba si se ha ganado el juego
  	  *
  	  * @return Un booleano que indica si se ha gano el juego
    */
	bool Victoria();

	/**
  	  * @brief Marca y desmarca una casilla
  	  *
  	  * @param fila Fila en la que se encuentra la casilla
  	  * @param columna Columna en la que se encuentra la casilla
  	  *
  	  * @return Un booleano que indica si se ha marcado correctamente
  	  *
  	  *	@pre La casilla no puede estar abierta
  	  *
  	  * @see EstadoCasilla
    */
	bool Marcar(int fila, int columna);

	/**
  	  * @brief Abre una casilla y su entorno recursivamente
  	  *
  	  * @param fila Fila en la que se encuentra la casilla
  	  * @param columna Columna en la que se encuentra la casilla
  	  *
  	  * @return Un booleano que indica si se ha abierto correctamente
  	  *
  	  *	@pre La casilla no puede estar abierta ni marcada
  	  *
  	  * @see EstadoCasilla
    */
	bool Abrir(int fila, int columna);

	/**
  	  * @brief Imprime el campo de minas en su estado actual
  	  *
      * @param El ostream por el que imprimir el campo, por defecto cout
    */
	void PrettyPrint(ostream& os = std::cout);

	/**
  	  * @brief Imprime el campo de minas con todas las casilla abiertas
  	  *
  	  * @return Un booleano que indica si se puede imprimir
  	  *
  	  * @pre Tiene que haber terminado el juego
    */
	bool TableroFin();

  /**
    * @brief Lee un campo de minas desde un istream, permite recuperar un juego guardado
    *
    * @param is Istream desde el que se leera el campo
    *
    * @return Si se ha leido correctamente
    */
  bool Leer(istream& is);

  /**
    * @brief Escribe un campo de minas desde un ostream, permite guardar el juego
    *
    * @param is Ostream a traves del que se escribirá el campo
    *
    * @return Si se ha escrito correctamente
    */
  bool Escribir(ostream& os);
};

#endif