#include <iostream>
#include <cstring>
#include "matriz_bit.h"
#include "matriz_operaciones.h"
using namespace std;

int main(int argc, char* argv[]){
	MatrizBit m1,resultado;

	if (argc < 2){
		cout << "Error en la lectura, introduzca operacion\n";
		return 1;
	}
	else{
		if (strcmp(argv[1],"AND") == 0){
			MatrizBit m2;
			if (argc > 4){
				cout << "Demasiados argumentos\n";
				return 1;
			}
			else if (argc == 4){
				Leer(argv[2],m1);
				Leer(argv[3],m2);
			}
			else if (argc == 3){
				Leer(cin,m1);
				Leer(argv[2],m2);
			}
			else if (argc == 2){
				Leer(cin,m1);
				Leer(cin,m2);
			}

			And(resultado,m1,m2);
			Escribir(cout,resultado);
		}
		else if (strcmp(argv[1],"OR") == 0){
			MatrizBit m2;
			if (argc > 4){
				cout << "Demasiados argumentos\n";
				return 1;
			}
			else if (argc == 4){
				Leer(argv[2],m1);
				Leer(argv[3],m2);
			}
			else if (argc == 3){
				Leer(cin,m1);
				Leer(argv[2],m2);
			}
			else if (argc == 2){
				Leer(cin,m1);
				Leer(cin,m2);
			}

			Or(resultado,m1,m2);
			Escribir(cout,resultado);
		}
		else if (strcmp(argv[1],"NOT") == 0){
			if (argc > 3){
				cout << "Demasiados argumentos\n";
				return 1;
			}
			else if (argc == 3){
				Leer(argv[2],m1);
			}
			else if (argc == 2){
				Leer(cin,m1);
			}

			Not(resultado,m1);
			Escribir(cout,resultado);
		}
		else if (strcmp(argv[1],"TRS") == 0){
			if (argc > 3){
				cout << "Demasiados argumentos\n";
				return 1;
			}
			else if (argc == 3){
				Leer(argv[2],m1);
			}
			else if (argc == 2){
				Leer(cin,m1);
			}

			Traspuesta(resultado,m1);
			Escribir(cout,resultado);
		}
		else {
			cout << "Operación inválida\n";
			return 1;
		}
	}
}