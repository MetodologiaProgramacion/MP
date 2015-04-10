#include <cmath>
#include "matriz_bit4.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
	if (fils * cols > 128 || fils < 0 || cols < 0)
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
	int columnas = m.dimension & (unsigned int)(pow(2.0,8.0) - 1);
	return columnas;
}
bool Get(const MatrizBit& m, int f, int c){
	int columnas = Columnas(m);
	int posicion = f * columnas + c;
	int cual_entero = posicion/32;
	int posicion_bit = posicion - 32*cual_entero;
	bool valor = (m.matriz[cual_entero] & (1 << posicion_bit)) >> posicion_bit;
	return valor;
}
void Set(MatrizBit& m, int f, int c, bool v){
	int filas = Filas(m);
	int columnas = Columnas(m);
	if (f < filas && c < columnas){
		int posicion = f * columnas + c;
		int cual_entero = posicion/32;
		int posicion_bit = posicion - 32*cual_entero;
		if (v)
			m.matriz[cual_entero] = m.matriz[cual_entero] | (v << posicion_bit);
		else
			m.matriz[cual_entero] = m.matriz[cual_entero] & (v << posicion_bit);
	}
}