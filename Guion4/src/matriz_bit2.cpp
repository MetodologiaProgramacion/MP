#include "matriz_bit2.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
	if (fils * cols >= 100 || fils < 0 || cols < 0)
		return false;
	else{
		m.filas = fils;
		m.columnas = cols;
		for (int i = 0; i <= fils*cols; i++){
			m.matriz[i] = 0;
		}
		return true;
	}
}
int Filas (const MatrizBit& m){
	return m.filas;
}
int Columnas( const MatrizBit& m){
	return m.columnas;
}
bool Get(const MatrizBit& m, int f, int c){
	int posicion = f * m.columnas + c;
	return m.matriz[posicion];
}
void Set(MatrizBit& m, int f, int c, bool v){
	if (f <= m.filas && c <= m.columnas)
		int posicion = f * m.columnas + c;
		m.matriz[posicion] = v;
}