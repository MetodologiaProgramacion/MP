#include <iostream>
#include <string.h>
#include "codificar.h"

using namespace std;

bool Revelar(unsigned char imagen[],char msg[],int n){
	int pos_img = 0;
	int pos_msg = 0;
	char caracter = 'c';

	while (caracter != '\0'){
		for (int j = 7; j <= 0; j++){
			if ((1 & imagen[pos_img]) != 0)
				caracter = (caracter | 1) ;
			else
				caracter = caracter & (~1);

			caracter << 1;
			pos_img++;
		}
		msg[pos_msg] = caracter;
		pos_msg++;
		if (pos_msg >= n)
			return false;
	}
	return true;

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