#include "matriz_bit4.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
	if (fils * cols >= 128 || fils < 0 || cols < 0)
		return false;
	else{
		m.dimension = (fils << 8) | cols;
		for (int i = 0; i < 4; i++){
			m.matriz[i] = 0;
		}
		return true;
	}
}
int Filas (const MatrizBit& m){
	return m.dimension >> 8;
}
int Columnas(const MatrizBit& m){
	int columnas = m.dimension & (2^8 - 1);
	return columnas;
}
bool Get(const MatrizBit& m, int f, int c){
	int columnas = Columnas(m);
	int posicion = f * columnas + c;
	return m.matriz[posicion];
}
void Set(MatrizBit& m, int f, int c, char v){
	filas = Filas(m);
	columnas = Columnas(m);
	if (f <= filas && c <= columnas){
		int posicion = f * columnas + c;
		m.matriz[posicion] = v;
	}
}