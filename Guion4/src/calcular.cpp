#include <iostream>
#include <cstring>
#include "matriz_bit.h"
#include "matriz_operaciones.h"
using namespace std;

void error(char*, char*);
void ok();

int main(int argc, char* argv[]){
	MatrizBit m1, resultado;

	if (argc < 2){
		error("entrada", "operación no declarada");
		return 1;
	}
	else{
		if (strcmp(argv[1],"AND") == 0){
			MatrizBit m2;
			if (argc > 4){
				error("entrada", "demasiados argumentos");
				return 1;
			}
			else if (argc == 4){
				Leer(argv[2],m1) ? ok() : error("lectura", "fallo al leer la matriz");
				Leer(argv[3],m2) ? ok() : error("lectura", "fallo al leer la matriz");
			}
			else if (argc == 3){
				Leer(cin,m1) ? ok() : error("lectura", "fallo al leer la matriz");
				Leer(argv[2],m2) ? ok() : error("lectura", "fallo al leer la matriz");
			}
			else if (argc == 2){
				Leer(cin,m1) ? ok() : error("lectura", "fallo al leer la matriz");
				Leer(cin,m2) ? ok() : error("lectura", "fallo al leer la matriz");
			}

			And(resultado,m1,m2) ? ok() : error("procesamiento", "fallo en la operación");
			Escribir(cout,resultado) ? ok() : error("escritura", "");
		}
		else if (strcmp(argv[1],"OR") == 0){
			MatrizBit m2;
			if (argc > 4){
				error("entrada", "demasiados argumentos");
				return 1;
			}
			else if (argc == 4){
				Leer(argv[2],m1) ? ok() : error("lectura", "fallo al leer la matriz");
				Leer(argv[3],m2) ? ok() : error("lectura", "fallo al leer la matriz");
			}
			else if (argc == 3){
				Leer(cin,m1) ? ok() : error("lectura", "fallo al leer la matriz");
				Leer(argv[2],m2) ? ok() : error("lectura", "fallo al leer la matriz");
			}
			else if (argc == 2){
				Leer(cin,m1) ? ok() : error("lectura", "fallo al leer la matriz");
				Leer(cin,m2) ? ok() : error("lectura", "fallo al leer la matriz");
			}

			Or(resultado,m1,m2) ? ok() : error("procesamiento", "fallo en la operación");
			Escribir(cout,resultado) ? ok() : error("escritura", "");
		}
		else if (strcmp(argv[1],"NOT") == 0){
			if (argc > 3){
				error("entrada", "demasiados argumentos");
				return 1;
			}
			else if (argc == 3){
				Leer(argv[2],m1) ? ok() : error("lectura", "fallo al leer la matriz");
			}
			else if (argc == 2){
				Leer(cin,m1) ? ok() : error("lectura", "fallo al leer la matriz");
			}

			Not(resultado,m1) ? ok() : error("procesamiento", "fallo en la operación");
			Escribir(cout,resultado) ? ok() : error("escritura", "");
		}
		else if (strcmp(argv[1],"TRS") == 0){
			if (argc > 3){
				error("entrada", "demasiados argumentos");
				return 1;
			}
			else if (argc == 3){
				Leer(argv[2],m1) ? ok() : error("lectura", "fallo al leer la matriz");
			}
			else if (argc == 2){
				Leer(cin,m1) ? ok() : error("lectura", "fallo al leer la matriz");
			}

			Traspuesta(resultado,m1) ? ok() : error("procesamiento", "fallo en la operación");
			Escribir(cout,resultado) ? ok() : error("escritura", "");
		}
		else {
			error("entrada", "operacion inválida");
			return 1;
		}
	}
}

void error(char* tipo, char* error){
	cout << "![Error de " << tipo << " ," << error << "]\n";
}

void ok(){
	;
}