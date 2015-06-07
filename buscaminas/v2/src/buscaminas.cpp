#include <iostream>
#include <fstream>
#include <string.h>
#include "tablero.h"
#include "CampoMinas.h"
using namespace std;

#define MAX_COMND_SIZE  768
#define MAX_PARMS  2
#define MAX_PARMS_SIZE  256

void empezar_juego(CampoMinas campo);
int parse_accion(char* accion);
int get_parametros(char* comando, char parametros[MAX_PARMS][MAX_PARMS_SIZE]);
int contar_parametros(char* comando);
void mostrar_ayuda();
int str_to_int(char* str);


int main(int argc, char** argv){
	bool iniciado_correcto = true;

	CampoMinas campo(10, 10, 20);

	if (argc == 4){
		campo = CampoMinas(str_to_int(argv[1]), str_to_int(argv[2]), str_to_int(argv[3]));
	} else if (argc == 2){
		ifstream ifs(argv[1]);
		if (ifs.good()){
			if(!campo.Leer(ifs)){
				cout << "Error leyendo el archivo";
				iniciado_correcto = false;
			}
		} else {
			cout << "No existe el archivo " << argv[1] << endl;
			iniciado_correcto = false;
		}
	} else if (argc == 1){
		ifstream ifs("save.txt");
		if (ifs.good())
			if(!campo.Leer(ifs))
				cout << "Error leyendo el archivo";
	} else {
		cout << "buscaminas [ archivo_guardado | filas columnas numero_minas ]" << endl;
		iniciado_correcto = false;
	}

	if (iniciado_correcto)
		empezar_juego(campo);

	return 0;
}

void empezar_juego(CampoMinas campo){
	int fils, cols;
	char comando[MAX_COMND_SIZE];
	int accion;
	char parametros[MAX_PARMS][MAX_PARMS_SIZE];
	int num_parametros;

	while(!campo.Victoria() && !campo.Explosion()){
		campo.PrettyPrint();
		cout << "Dime acción y posición (fil y col): ";
		cin.getline(comando, MAX_COMND_SIZE);
		accion = parse_accion(comando);
		num_parametros = get_parametros(comando, parametros);


		if (accion == 1){
			if (num_parametros == 2){
				fils = str_to_int(parametros[0]);
				cols = str_to_int(parametros[1]);
				campo.Abrir(fils, cols);
			} else{
				cout << "Comando abrir: a|abrir fila columna\n";
			}
		}else if (accion == 2){
			if (num_parametros == 2){
				fils = str_to_int(parametros[0]);
				cols = str_to_int(parametros[1]);
				campo.Marcar(fils, cols);
			} else{
				cout << "Comando marcar: m|marcar fila columna\n";
			}
		}else if (accion == 3){
			ofstream ofs;
			if (num_parametros != 0){
				ofs.open(parametros[0]);
			}else{
				ofs.open("save.txt");
			}
			campo.Escribir(ofs);
			ofs.close();
		}else if (accion == 4){
			mostrar_ayuda();
		}else{
			cout << "Acción no valida\n";
		}
	}

	if (campo.Victoria())
		cout << "Has ganado\n";
	else
		cout << "Has perdido\n";

	campo.TableroFin();
}

int parse_accion(char* comando){
	char* separacion = strchr(comando, ' ');
	int res;

	if (separacion != NULL)
		separacion[0] = '\0';

	if (strcmp(comando, "a") == 0 || strcmp(comando, "abrir") == 0){
		res = 1;
	} else if (strcmp(comando, "m") == 0 || strcmp(comando, "marcar") == 0){
		res = 2;
	} else if (strcmp(comando, "s") == 0 || strcmp(comando, "salvar") == 0){
		res = 3;
	} else if (strcmp(comando, "h") == 0 || strcmp(comando, "help") == 0){
		res = 4;
	} else {
		res = 0;
	}

	if (separacion != NULL)
		separacion[0] = ' ';
	return res;
}

int get_parametros(char* comando, char parametros[MAX_PARMS][MAX_PARMS_SIZE]){
	int num_parametros = contar_parametros(comando);
	char* lseparacion;
	char* rseparacion = comando;
	int tamano;

	if (num_parametros > MAX_PARMS)
		num_parametros = MAX_PARMS;

	for (int i=0; i<num_parametros; i++, rseparacion++){
		if (strchr(rseparacion, ' ') == NULL){
			rseparacion = strchr(rseparacion, '\0');
			lseparacion = strchr(lseparacion + 1, ' ');
		} else {
			lseparacion = strchr(rseparacion, ' ');
			if (strchr(lseparacion + 1, ' ') == NULL)
				rseparacion = strchr(lseparacion + 1, '\0');
			else
				rseparacion = strchr(lseparacion + 1, ' ');
		}
		tamano = int(rseparacion - lseparacion);
		for (int j=0; j<tamano-1; j++){
			parametros[i][j] = lseparacion[j+1];
		}
		parametros[i][tamano-1] = '\0';
	}

	return num_parametros;
}

int contar_parametros(char* comando){
	int num_parametros=0;

	for (int i=0; comando[i] != '\0'; i++){
		if (isspace(comando[i]) && isalnum(comando[i+1])){
			num_parametros++;
		}
	}

	return num_parametros;
}

void mostrar_ayuda(){
	ifstream ifs("help.txt");

	cout << ifs.rdbuf();
}

int str_to_int(char* str){
	int num = 0;

	for (int i=0; str[i] != '\0'; i++){
		num = num*10 + str[i]-'0';
	}

	return num;
}