#include <iostream>
#include <string.h>
#include "codificar.h"

using namespace std;

void InsertarCaracter(unsigned char imagen[], char caracter, int& comienzo);


bool Ocultar(unsigned char imagen[], int longitud, char msg[]){
	char caracter;
	int ultimo_byte_cambiado = 0;
	int longitud_msg = strlen(msg);
	bool correcto = longitud >= longitud_msg*8;

	if (correcto){
		for (int i=0; i < longitud_msg; i++){
			caracter = msg[i];
			InsertarCaracter(imagen, caracter, ultimo_byte_cambiado);
		}
		InsertarCaracter(imagen, '\0', ultimo_byte_cambiado);
	}

	return correcto;
}

void InsertarCaracter(unsigned char imagen[], char caracter, int& comienzo){
	char bit;
	for (int i=0; i < 8; i++, comienzo++){
		bit = caracter & (1 << 7);
		bit = bit >> 7;
		caracter = caracter << 1;

		if(bit == 0){
			imagen[comienzo] = imagen[comienzo] & ~1;
		} else {
			imagen[comienzo] = imagen[comienzo] | 1;
		}
	}
}

bool Revelar(unsigned char imagen[],char msg[],int n){
	int pos_img = 0;
	int pos_msg = 0;
	char caracter = 1;

	while (caracter != '\0'){
		for (int j=0; j < 8; j++){
			caracter = caracter << 1;

			if ((1 & imagen[pos_img]) == 1){
				caracter = caracter | 1;
			}

			pos_img++;
		}

		msg[pos_msg] = caracter;
		pos_msg++;
		if (pos_msg >= n)
			return false;
	}
	return true;
}