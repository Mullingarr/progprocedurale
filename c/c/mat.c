#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#undef DEBUG
#define DEBUG 1

unsigned short mat1[3][3];

int main(int argc, const char *argv[]){
	printf("immeettti l'ordine della matrice: ")
	scanf("%d", &n);

	mat = calloc(nn ,sizeof(unsigned short*));

	for(int i = 0; i < n; i++)
		mat[i] = calloc(n, sizeof(unsigned short));

	srand(time(NULL)%1000000);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			mat[i][j] = rand()%1000;
		}
	}

	#if DEBUG

	
	
}
