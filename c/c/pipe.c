#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Massima lunghezza dell'input inserito
#define N 100
typedef int pipe_t[2];

int main(int argc, char *argv[]){
	pipe_t pp;
	char buff[N];
	//creazione della pipe
	if(pipe(pp) < 0){
		fprintf(stderr, "Errore nella creazione della pipe\n");
		exit(1);
	}
	//creazione del processo figlio
	switch(fork()){
		case -1:
			fprintf(stderr, "Impossibile creare processo figlio");
			exit(2);
			break;
		case  0:
			/**
			 * Chiudo il canale di lettura della pipe, in quanto il processo figlio deve
			 * solo scrivere sulla pipe e il canale di lettura non mi interessa
			 * */
			close(pp[0]);
			//chiedo all'utente di inserire una stringa
			printf("Stringa da inserire sulla pipe:\n");
			fgets(buff, N, stdin);
			buff[strlen(buff)] = '\0';
			//scrivo la stringa sulla pipe
			if(write(pp[1], buff, N) < 0){
				printf("Errore nella scrittura su pipe\n");
				exit(3);
			}
			close(pp[1]);
			exit(0);
			break;
		default: //codice del padre
			//chiudo il canale di scrittura dal lato del padre, dato che deve solo leggere dalla pipe
			close(pp[1]);
			printf("padre: Attendo che figlio termini\n");
			wait((int *) 0);
			//il figlio e' terminato, leggo la stringa dalla pipe
			if(read(pp[0], buff, N) < 0){
				fprintf(stderr, "errore nella lettura della pipe\n");
				exit(1);
			}
			printf("figlio ha scritto: %s sulla pipe\n", buff);
			exit(0);
			break;
	}
	return 0;
}