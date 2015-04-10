#include <iostream>
#include <fructose/fructose.h>
#include "matriz_bit.cpp"


struct tester : public fructose::test_base<tester>{
	void test_Inicializar(const std::string& test_name){
		MatrizBit m, m_ref;
		m_ref.f = 2;
		m_ref.c = 3;

		Inicializar(m, 2, 3);
		fructose_assert_eq(m.f, m_ref.f);
		fructose_assert_eq(m.c, m_ref.c);

		for (int i=0; i < m.f; i++){
			for (int j=0; j < m.c; j++){
				fructose_assert_eq(m.matriz[i][j], 0);
			}
		}
	}
	void test_Filas(const std::string& test_name){
		MatrizBit m;
		Inicializar(m, 2, 3);

		fructose_assert_eq(Filas(m), 2);
	}
	void test_Columnas(const std::string& test_name){
		MatrizBit m;
		Inicializar(m, 2, 3);

		fructose_assert_eq(Columnas(m), 3);
	}
	void test_Set(const std::string& test_name){
		MatrizBit m;
		Inicializar(m, 2, 3);
		Set(m, 1, 2, true);

		fructose_assert_eq(m.matriz[1][2], true);
	}
	void test_Get(const std::string& test_name){
		MatrizBit m;
		Inicializar(m, 2, 3);
		Set(m, 1, 2, true);

		fructose_assert_eq(Get(m,1,2), true);
	}
};


int main(int argc,char** argv){
	tester tests;
	tests.add_test("test_Inicializar", &tester::test_Inicializar);
	tests.add_test("test_Filas", &tester::test_Filas);
	tests.add_test("test_Columnas", &tester::test_Columnas);
	tests.add_test("test_Set", &tester::test_Set);
	tests.add_test("test_Get", &tester::test_Get);
	return tests.run(argc, argv);
}