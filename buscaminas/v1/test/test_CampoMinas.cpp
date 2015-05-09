#include <iostream>
#include <fructose/fructose.h>
#include "tablero.cpp"
#include "CampoMinas.cpp"

class TestCampoMinas : CampoMinas{
public:
	TestCampoMinas(int f, int c, int n) : CampoMinas(f, c, n){}

	int get_numero_minas(){
		int filas = Filas();
		int columnas = Columnas();

		int n_minas = 0;
		for (int i=0; i < filas; i++){
			for (int j=0; j < columnas; j++){
				if (tablero.get_contenido_casilla(i, j) == MINA)
					n_minas++;
			}
		}

		return n_minas;
	}

	int num_minas_cerca(int f, int c){
		return NumMinasCerca(f, c);
	}
};

struct tester : public fructose::test_base<tester>{
	void test_Inicializar(const std::string& test_name){
		int f = 10;
		int c = 10;
		int n = 20;

		// Comprobamos que tiene el numero de minas correcto
		TestCampoMinas campo(f, c, n);
		fructose_assert_eq(campo.get_numero_minas(), n);
	}

	void test_PrettyPrint(const std::string& test_name){
		// Caso 1X1
		int f = 1;
		int c = 1;
		int n = 1;

		cout << f << "X" << c << endl;
		CampoMinas c1(f, c, n);
		c1.PrettyPrint();

		// Caso 10X5
		f = 10;
		c = 5;
		n = 1;

		cout << f << "X" << c << endl;
		CampoMinas c2(f, c, n);
		c2.PrettyPrint();

		// Caso 5X10
		f = 5;
		c = 10;
		n = 1;

		cout << f << "X" << c << endl;
		CampoMinas c3(f, c, n);
		c3.Abrir(3,4);
		c3.PrettyPrint();

		// Caso 20X20
		f = 20;
		c = 20;
		n = 100;

		cout << f << "X" << c << endl;
		CampoMinas c4(f, c, n);
		c4.Abrir(15, 9);
		c4.PrettyPrint();
	}

	void test_NumFilasCerca(const std::string& test_name){
		TestCampoMinas campo(6, 9, 25);
		int s = 0;

		s = campo.num_minas_cerca(1,1) + campo.num_minas_cerca(1,4) + campo.num_minas_cerca(1,7) +
			campo.num_minas_cerca(4,1) + campo.num_minas_cerca(4,4) + campo.num_minas_cerca(4,7);

		fructose_assert_eq(s, 25);
	}
};

int main(int argc,char** argv){
	tester tests;
	tests.add_test("test_Inicializar", &tester::test_Inicializar);
	tests.add_test("test_PrettyPrint", &tester::test_PrettyPrint);
	tests.add_test("test_NumFilasCerca", &tester::test_NumFilasCerca);
	return tests.run(argc, argv);
}