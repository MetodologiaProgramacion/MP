#include <iostream>
#include "codificar.h"
#include "imagenES.h"

using namespace std;

int main(){
	const int MAXBUFFER = 1000000;
	const int MAXNOMBRE = 100;
	const int MAXMSG = 10000;
	int filas, columnas;
	unsigned char imagen[MAXBUFFER];
	char nombre[MAXNOMBRE];
	char msg[MAXMSG];
	TipoImagen tipo;
	bool error = false;

	cout << "Introduzca el nombre de la imagen: ";
	cin.getline(nombre, MAXNOMBRE);
	tipo = LeerTipoImagen(nombre,filas,columnas);

	if (tipo == IMG_PPM){
		if (! LeerImagenPPM(nombre,filas,columnas,imagen))
			error = true;
	}
	else if (tipo == IMG_PGM){
		if (! LeerImagenPGM(nombre,filas,columnas,imagen))
			error = true;
	}
	else
		error = true;

	if (error)
		cout << "\nError en la lectura de la imagen, fichero no encontrado o formato no válido\n";
	else{
		if (Revelar(imagen,msg,MAXMSG))
			cout << "El mensaje oculto es:\n" << msg << endl;
		else
			cout << "La imagen no contiene ningún mensaje";
	}

}