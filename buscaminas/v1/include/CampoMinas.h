#include <cstdlib>
#include <ctime>
#include "tablero.h"

using namespace std;

class CampoMinas{
private:
	Tablero tablero;

public:
	CampoMinas(int f, int c, int n_minas)
	:tablero(f,c);
	int Filas();
	int Columnas();
	bool Explosion();
	bool Victotoria();
	bool Marcar();
	bool Abrir();
	bool PrettyPrint();
	bool TableroFin();
}