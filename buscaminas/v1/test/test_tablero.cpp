#include <iostream>
#include <fructose/fructose.h>
#include "tablero.cpp"

struct tester : public fructose::test_base<tester>{
	void test_Inicializar(const std::string& test_name){
		int f = 9;
		int c = 9;
		Tablero tablero(f, c);
		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				fructose_assert_eq(tablero.get_estado_casilla(i,j), CERRADA);
				fructose_assert_eq(tablero.get_contenido_casilla(i,j), VACIA);
			}
		}
	}

	void test_filas_columnas(const std::string& test_name){
		int f = 9;
		int c = 12;
		Tablero tablero(f, c);
		fructose_assert_eq(tablero.get_filas(), f);
		fructose_assert_eq(tablero.get_columnas(), c);
	}

	void test_estado_casilla(const std::string& test_name){
		int f=10;
		int c=10;
		Tablero tablero(f, c);

		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				tablero.abrir_casilla(f, c);
			}
		}
		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				fructose_assert_eq(tablero.get_estado_casilla(f, c), ABIERTA);
			}
		}

		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				tablero.marcar_casilla(f, c);
			}
		}
		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				fructose_assert_eq(tablero.get_estado_casilla(f, c), MARCADA);
			}
		}
	}

	void test_contenido_casilla(const std::string& test_name){
		int f=10;
		int c=10;
		Tablero tablero(f, c);

		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				tablero.poner_mina(f, c);
			}
		}
		for (int i=0; i < f; i++){
			for (int j=0; j < c; j++){
				fructose_assert_eq(tablero.get_contenido_casilla(f, c), MINA);
			}
		}
	}
};

int main(int argc,char** argv){
	tester tests;
	tests.add_test("test_Inicializar", &tester::test_Inicializar);
	tests.add_test("test_filas_columnas", &tester::test_filas_columnas);
	tests.add_test("test_estado_casilla", &tester::test_estado_casilla);
	tests.add_test("test_contenido_casilla", &tester::test_contenido_casilla);
	return tests.run(argc, argv);
}