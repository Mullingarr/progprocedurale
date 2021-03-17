#include <stdio.h>

/**
 * Per ottenere codice altamente efficiente bisogna evitare di fare
 * chiamate di funzione di poche righe di codice
 * "espansione in linea del codice"
 **/

#define Min(x, y) ((x)<(y)?(x):(y)) //le parentesi forzano la valutazione
#define Quadrato(x) ((x)*(x))

int main(int argc, const char* argv[]){

	int a, b, c;
	a = 10; b = 20;

	c= Min(a, b);
	printf("Minimo tra %d e %d: %d\n", a, b, c);
	printf("Quadrato di %d: %d\n", a, Quadrato(a+b)); 

	return 0;

}

