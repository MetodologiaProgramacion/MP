#include <iostream>
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
}