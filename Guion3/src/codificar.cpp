#include "codificar.h"
#include <string.h>

void InsertaCaracter(unsigned char[] imagen, char caracter, char& comienzo);


bool Ocultar(unsigned char[] imagen, int longitud, char[] msg){
	char caracter;
	int ultimo_byte_cambiado;
	int longitud_msg = strlen(msg);
	bool correcto = longitud >= longitud_msg;

	if (correcto){
		caracter = msg[0];
		InsertaCaracter(imagen, caracter, ultimo_byte_cambiado);
		for (int i=1; i < longitud_msg; i++){
			caracter = msg[i];
			InsertaCaracter(imagen, caracter, ++ultimo_byte_cambiado);
		}
	}

	return correcto;
}

void InsertaCaracter(unsigned char[] imagen, char caracter, char& comienzo){
	char extr = 1;
	char bit;
	for (int=0; i < 8; i++, comienzo++){
		bit = caracter & (extr << i);
		bit = bit >> i;

		if(bit == 1){
			imagen[comienzo] = imagen[comienzo] | (extr << i);
		} else {
			imagen[comienzo] = imagen[comienzo] & ~(extr << i);
		}
	}
}