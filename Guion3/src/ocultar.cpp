#include <iostream>
#include "codificar.h"
#include "imagenES.h"
using namespace std;

bool OcultarPGM(char[], char[], char[]);
bool OcultarPPM(char[], char[], char[]);


int main(){
	const int MAX_NOMBRE = 100;
	const int MAX_MSG = 100000;
	char nombre_imagen_entrada[MAX_NOMBRE];
	char nombre_imagen_salida[MAX_NOMBRE];
	char msg[MAX_MSG];
	int f, c;
	bool correcto;
	TipoImagen tipo_imagen;

	cout << "Introduzca la imagen de entrada:\n";
	cin.getline(nombre_imagen_entrada, MAX_NOMBRE);
	cout << "Introduzca la imagen de salida:\n";
	cin.getline(nombre_imagen_salida, MAX_NOMBRE);
	cout << "Introduzca el mensaje: (max " << MAX_MSG << " chars " << ")\n";
	cin.getline(msg, MAX_MSG);

	tipo_imagen = LeerTipoImagen(nombre_imagen_entrada, f, c);

	switch(tipo_imagen){
		case IMG_PGM: correcto = OcultarPGM(nombre_imagen_entrada, nombre_imagen_salida, msg);break;
		case IMG_PPM: correcto = OcultarPPM(nombre_imagen_entrada, nombre_imagen_salida, msg);break;
		case IMG_DESCONOCIDO: cout << "Error, formato no aceptado\n"; correcto = false;
	}

	if(correcto){
		cout << "Mensje ocultado con exito\n";
	} else {
		cout << "Error al ocultar el mensaje\n";
	}
}

bool OcultarPGM(char nombre_imagen_entrada[], char nombre_imagen_salida[], char msg[]){
	const int MAX_BUFFER = 1000000;
	unsigned char buffer[MAX_BUFFER];
	int filas, columnas;
	bool correcto;

	correcto = LeerImagenPGM(nombre_imagen_entrada, filas, columnas, buffer);
	if (correcto){
		correcto = Ocultar(buffer, filas*columnas, msg);
	}
	if (correcto){
		correcto = EscribirImagenPGM(nombre_imagen_salida, buffer, filas, columnas);
	}

	return correcto;
}

bool OcultarPPM(char nombre_imagen_entrada[], char nombre_imagen_salida[], char msg[]){
	const int MAX_BUFFER = 1000000;
	unsigned char buffer[MAX_BUFFER];
	int filas, columnas;
	bool correcto;

	correcto = LeerImagenPPM(nombre_imagen_entrada, filas, columnas, buffer);
	if (correcto){
		correcto = Ocultar(buffer, filas*columnas, msg);
	}
	if (correcto){
		correcto = EscribirImagenPPM(nombre_imagen_salida, buffer, filas, columnas);
	}

	return correcto;
}