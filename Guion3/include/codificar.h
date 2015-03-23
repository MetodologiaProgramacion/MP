/**
  * @file codificar.h
  * @brief Fichero cabecera para la codificacion de mensajes en imágenes
  *
  * Permite la codificacion de mensajes en mapas de bits
  *
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_


/**
  * @brief Oculta un mensaje en un mapa de bits
  *
  * @param mapa de bits que conforma la imagen.
  * @param longitud del mapa de bits en forma de vector.
  * @param cadena c con el mensaje a ocultar.
  * @return Devuelve si se ha ocultado con exito
  * @pre la imagen debe tener una longitud ocho veces mayor al mensaje.
  */
bool Ocultar(unsigned char imagen[], int longitud, char msg[]);

/**
  * @brief Revela un mensaje oculto en un mapa de bits
  *
  * @param mapa de bits que conforma la imagen.
  * @param cadena c en la que se almacena el mensaje oculto.
  * @param longitud maxima que se llegara a leer.
  * @return Devuelve si se ha revelado con exito
  */
bool Revelar(unsigned char imagen[], char msg[], int n);

#endif