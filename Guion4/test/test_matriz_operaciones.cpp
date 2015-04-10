#include <iostream>
#include <fructose/fructose.h>
#include "matriz_bit.cpp"
#include "matriz_operaciones.cpp"

struct tester : public fructose::test_base<tester>{
	void test_ES(const std::string& test_name){
		MatrizBit m;

		std::stringbuf buffer;
		std::ostream os(&buffer);
		std::istream is(&buffer);
		os << "2 2\n0 1\n1 1\0";
		if (Leer(is, m))
			Escribir(std::cout, m);

		MatrizBit m1;
		if (Leer("../matrices/ejemplo1.mat", m1))
			Escribir(std::cout, m1);

		MatrizBit m2;
		if (Leer("../matrices/ejemplo2.mat", m2))
			Escribir(std::cout, m2);

		MatrizBit m3;
		if (Leer("../matrices/ejemplo3.mat", m3))
			Escribir(std::cout, m3);

		MatrizBit m4;
		if (Leer("../matrices/ejemplo4.mat", m4))
			Escribir(std::cout, m4);

		MatrizBit m5;
		if (Leer("../matrices/ejemplo5.mat", m5))
			Escribir(std::cout, m5);

		MatrizBit m6;
		if (Leer("../matrices/ejemplo6.mat", m6))
			Escribir(std::cout, m6);
	}
	void test_IgnorarCabecera(const std::string& test_name){
		char m_ej1[100];
		ifstream s_ej1("../matrices/ejemplo1.mat");
		IgnorarCabecera(s_ej1);
		s_ej1.get(m_ej1, 100, EOF);
		std::cout << m_ej1 << std::endl;
	}
	void test_TieneCabecera(const std::string& test_name){
		std::stringbuf buffer;
		std::ostream os(&buffer);
		std::istream is(&buffer);
		os << "2 2\n1 0\n0 1\0";
		fructose_assert(TieneCabecera(is));
		fructose_assert(TieneCabecera(is));

		std::stringbuf buffer2;
		std::ostream os2(&buffer2);
		std::istream is2(&buffer2);
		os2 << "1 1\n1\0";
		fructose_assert(TieneCabecera(is2));

		std::stringbuf buffer3;
		std::ostream os3(&buffer3);
		std::istream is3(&buffer3);
		os3 << "1 0\n1 0\0";
		fructose_assert(!TieneCabecera(is3));

		std::stringbuf buffer4;
		std::ostream os4(&buffer4);
		std::istream is4(&buffer4);
		os4 << "X .\n. X\0";
		fructose_assert(!TieneCabecera(is4));
	}
	void test_LeerTipoEntrada(const std::string& test_name){
		std::stringbuf buffer;
		std::ostream os(&buffer);
		std::istream is(&buffer);
		os << "2 2\n1 0\n0 1\0";
		fructose_assert_eq(LeerTipoEntrada(is), BINARIA_CABECERA);

		std::stringbuf buffer2;
		std::ostream os2(&buffer2);
		std::istream is2(&buffer2);
		os2 << "1 1\n1 0\0";
		fructose_assert_eq(LeerTipoEntrada(is2), BINARIA);

		std::stringbuf buffer3;
		std::ostream os3(&buffer3);
		std::istream is3(&buffer3);
		os3 << "2 2\nX .\nX .\0";
		fructose_assert_eq(LeerTipoEntrada(is3), MARCADA_CABECERA);

		std::stringbuf buffer4;
		std::ostream os4(&buffer4);
		std::istream is4(&buffer4);
		os4 << ". X\nX .\0";
		fructose_assert_eq(LeerTipoEntrada(is4), MARCADA);
	}
	void test_FilasCabecera(const std::string& test_name){
		char cabecera[MAX_CABECERA];

		std::stringbuf buffer;
		std::ostream os(&buffer);
		std::istream is(&buffer);
		os << "2 2\n1 0\n0 1\0";
		Cabecera(is, cabecera);
		fructose_assert_eq(FilasCabecera(cabecera), 2);

		std::stringbuf buffer2;
		std::ostream os2(&buffer2);
		std::istream is2(&buffer2);
		os2 << "1 2\nX .\0";
		Cabecera(is2, cabecera);
		fructose_assert_eq(FilasCabecera(cabecera), 1);

		std::stringbuf buffer3;
		std::ostream os3(&buffer3);
		std::istream is3(&buffer3);
		os3 << "12 25\nX .\0";
		Cabecera(is3, cabecera);
		fructose_assert_eq(FilasCabecera(cabecera), 12);
	}
	void test_ColumnasCabecera(const std::string& test_name){
		char cabecera[MAX_CABECERA];

		std::stringbuf buffer;
		std::ostream os(&buffer);
		std::istream is(&buffer);
		os << "2 2\n1 0\n0 1\0";
		Cabecera(is, cabecera);
		fructose_assert_eq(ColumnasCabecera(cabecera), 2);

		std::stringbuf buffer2;
		std::ostream os2(&buffer2);
		std::istream is2(&buffer2);
		os2 << "1 2\nX .\0";
		Cabecera(is2, cabecera);
		fructose_assert_eq(ColumnasCabecera(cabecera), 2);

		std::stringbuf buffer3;
		std::ostream os3(&buffer3);
		std::istream is3(&buffer3);
		os3 << "12 25\nX .\0";
		Cabecera(is3, cabecera);
		fructose_assert_eq(ColumnasCabecera(cabecera), 25);
	}
	void test_FilasIstream(const std::string& test_name){
		std::stringbuf buffer;
		std::ostream os(&buffer);
		std::istream is(&buffer);
		os << "1 1\n1 0\n0 1\0";
		fructose_assert_eq(FilasIstream(is), 3);

		std::stringbuf buffer2;
		std::ostream os2(&buffer2);
		std::istream is2(&buffer2);
		os2 << "0 1 1 0 1\0";
		fructose_assert_eq(FilasIstream(is2), 1);
	}
	void test_ColumnasIstream(const std::string& test_name){
		std::stringbuf buffer;
		std::ostream os(&buffer);
		std::istream is(&buffer);
		os << "1 1\n1 0\n0 1\0";
		fructose_assert_eq(ColumnasIstream(is), 2);
		fructose_assert_eq(ColumnasIstream(is), 2);

		std::stringbuf buffer2;
		std::ostream os2(&buffer2);
		std::istream is2(&buffer2);
		os2 << "0 1 1 0 1\0";
		fructose_assert_eq(ColumnasIstream(is2), 5);
	}
	void test_And(const std::string& test_name){
		MatrizBit res1;
		MatrizBit m1;
		MatrizBit m2;
		Leer("../matrices/ejemplo1.mat", m1);
		Leer("../matrices/ejemplo2.mat", m2);
		if (And(res1, m1, m2))
			Escribir(std::cout, res1);

		MatrizBit res2;
		MatrizBit m3;
		MatrizBit m4;
		Leer("../matrices/ejemplo3.mat", m3);
		Leer("../matrices/ejemplo4.mat", m4);
		if (And(res2, m3, m4))
			Escribir(std::cout, res2);

		MatrizBit res3;
		MatrizBit m5;
		MatrizBit m6;
		Leer("../matrices/ejemplo5.mat", m5);
		Leer("../matrices/ejemplo6.mat", m6);
		if (And(res3, m5, m6))
			Escribir(std::cout, res3);
	}
	void test_Or(const std::string& test_name){
		MatrizBit res1;
		MatrizBit m1;
		MatrizBit m2;
		Leer("../matrices/ejemplo1.mat", m1);
		Leer("../matrices/ejemplo2.mat", m2);
		if (Or(res1, m1, m2))
			Escribir(std::cout, res1);

		MatrizBit res2;
		MatrizBit m3;
		MatrizBit m4;
		Leer("../matrices/ejemplo3.mat", m3);
		Leer("../matrices/ejemplo4.mat", m4);
		if (Or(res2, m3, m4))
			Escribir(std::cout, res2);

		MatrizBit res3;
		MatrizBit m5;
		MatrizBit m6;
		Leer("../matrices/ejemplo5.mat", m5);
		Leer("../matrices/ejemplo6.mat", m6);
		if (Or(res3, m5, m6))
			Escribir(std::cout, res3);
	}
	void test_Not(const std::string& test_name){
		MatrizBit res1;
		MatrizBit m1;
		Leer("../matrices/ejemplo1.mat", m1);
		if (Not(res1, m1))
			Escribir(std::cout, res1);

		MatrizBit res2;
		MatrizBit m2;
		Leer("../matrices/ejemplo2.mat", m2);
		if (Not(res2, m2))
			Escribir(std::cout, res2);

		MatrizBit res3;
		MatrizBit m3;
		Leer("../matrices/ejemplo3.mat", m3);
		if (Not(res3, m3))
			Escribir(std::cout, res3);

		MatrizBit res4;
		MatrizBit m4;
		Leer("../matrices/ejemplo4.mat", m4);
		if (Not(res4, m4))
			Escribir(std::cout, res4);

		MatrizBit res5;
		MatrizBit m5;
		Leer("../matrices/ejemplo5.mat", m5);
		if (Not(res5, m5))
		Escribir(std::cout, res5);

		MatrizBit res6;
		MatrizBit m6;
		Leer("../matrices/ejemplo6.mat", m6);
		if (Not(res6, m6))
			Escribir(std::cout, res6);
	}
};


int main(int argc, char** argv){
	tester tests;
	tests.add_test("test_ES", &tester::test_ES);
	tests.add_test("test_IgnorarCabecera", &tester::test_IgnorarCabecera);
	tests.add_test("test_TieneCabecera", &tester::test_TieneCabecera);
	tests.add_test("test_LeerTipoEntrada", &tester::test_LeerTipoEntrada);
	tests.add_test("test_FilasCabecera", &tester::test_FilasCabecera);
	tests.add_test("test_ColumnasCabecera", &tester::test_ColumnasCabecera);
	tests.add_test("test_FilasIstream", &tester::test_FilasIstream);
	tests.add_test("test_ColumnasIstream", &tester::test_ColumnasIstream);
	tests.add_test("test_And", &tester::test_And);
	tests.add_test("test_Or", &tester::test_Or);
	tests.add_test("test_Not", &tester::test_Not);
	return tests.run(argc, argv);
}