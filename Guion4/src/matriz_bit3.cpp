#include "matriz_bit3.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
	if (fils * cols >= 100 || fils < 0 || cols < 0)
		return false;
	else{
		m.dimension = (fils << 16) | cols;
		for (int i = 0; i < fils*cols; i++){
			m.matriz[i] = '0';
		}
		return true;
	}
}
int Filas (const MatrizBit& m){
	return m.dimension >> 16;
}
int Columnas(const MatrizBit& m){
	int columnas = m.dimension & (2^16 - 1);
	return columnas;
}
bool Get(const MatrizBit& m, int f, int c){
	int columnas = Columnas(m);
	int posicion = f * columnas + c;
	return m.matriz[posicion - '0'];
}
void Set(MatrizBit& m, int f, int c, bool v){
	int filas = Filas(m);
	int columnas = Columnas(m);
	if (f < filas && c < columnas){
		int posicion = f * columnas + c;
		m.matriz[posicion] = (char)v + '0';
	}
}