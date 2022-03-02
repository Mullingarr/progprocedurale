#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 100

char **doubleArray(char **, int);
void freeArray(char **, int);
int strLength(char *);
void printArray(char **, int);

/**
 * Nota:
 *  prova a implementare la funzione:
 *  Date 2 stringhe, ritorna 0 se sono uguali
 *  1 se sono diverse
 */
int strCmp(char *, char *);

int main(){

	char letta[M];
	char **str = (char **) malloc(100 * sizeof(char*)); //array in cui conserviamo le stringhe
    for(int i = 0; i < M; i++)
        str[i] = (char *) malloc(100 * sizeof(char));
    printf("matrix init complete\n");

    printf("Inserisci stringa, il programma si ferma con l'inserimento di stop\n");
    printf(">");
	scanf("%s", letta);
	int i = 0;

    if((strcmp(letta, "stop")) == 0){
        printf("inserisci piu' di una stringa!\n");
        return -1;
    }
    do{
        printf("Stringa inserita: %s\n", letta);
        if(i < 100){
            strcpy(str[i], letta); //copiamo la stringa letta in str -> ricordati che gli array non sono assignable
            printf("%d: %s\n", i, str[i]);
            i++;
        }else{
            printf("Duplicazione grandezza array\n");
            doubleArray(str, i);
        }
        printf(">");
        scanf("%s", letta);
    }while((strcmp(letta, "stop")) != 0);

	//letta stop
	printf("inserisci lunghezza l\n");
	int l;
	scanf("%d", &l);
	int num = 0;
    printf("Cerco stringhe di lunghezza l: %d\n", l);
	for(int j = 0; j < i; j++){
		char *s = str[j];
        printf("analizzo %s\n", s);
		if(strLength(s) == l)
			num++;
	}
    printArray(str, i);
	printf("Numero di stringhe di lunghezza %d: %d\n", l, num);
    printf("\n");
    freeArray(str, i);
    return 0;
}

void printArray(char **str, int i){
    for(int j = 0; j < i; j++)
        printf("%d: %s\n", j, str[j]);
}

char **doubleArray(char **str, int i){
	char **arr = (char **) malloc((N + i + 1) * sizeof(char));
	for(int j = 0; j < i+1; j++){
		strcpy(arr[j], str[j]);
	}
	return arr;
}

/**
 * Libera lo spazio allocato all'array multidimensionale
 * @param str
 * @param i il numero di stringhe presenti presenti nell'array
 */
void freeArray(char **str, int i){
    for(int j = 0; j < i; j++){
        printf("libero pos j: %d\n", j);
        free(str[j]);
    }
    free(str);
}

/**
 * Ritorna la lunghezza della stringa passata
 * il ciclo while e il ciclo for fanno la stessa
 * cosa, il for è più conciso
 * @param str
 * @return
 */
int strLength(char *str){
    /**
    int count = 0;
	while(*str != '\0'){
        count++;
        str++;
    }
     **/
    int i = 0;
    for(; *str != '\0'; str++)
        i++;
    return i;
}