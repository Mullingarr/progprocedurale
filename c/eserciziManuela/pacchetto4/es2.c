//
// Created by Mattia Lunardi on 21/02/22.
//

/**
* Esercizio 2
 *
 * Scrivere un programma che legga in ingresso un array di N numeri compresi tra 0 e 9
 * (con N scelto dall’utente e compreso tra 1 e 100)
 * e stampi a video i numeri che compaiono nell’array con frequenza massima.
    Esempio: input: [1, 5, 9, 3, 5, 2, 9] -> output: 5 9
*/

#include <stdio.h>

int leggiNumero(int min, int max);

#define MAX_DIM 100

int main()
{
    int dim, i, freq_max;
    int seq[MAX_DIM];
    int conteggio[10];

    printf("Lunghezza della sequenza da inserire?\n");
    dim = leggiNumero(1, MAX_DIM);

    printf("Valori delle sequenza?\n");
    for(i = 0; i < dim; i++) {
        printf("posizione %d\n", i);
        seq[i] = leggiNumero(0, 9);
    }

    // inizializzo a 0 il conteggio dei valori
    for(i = 0; i < 10; i++)
        conteggio[i] = 0;

    // conto il numero di occorrenze di ciascun valore in seq
    // NOTA: siamo certi che tutti i valori sono compresi tra 0 e 9
    for(i = 0; i < dim; i++)
        conteggio[seq[i]]++;

    // cerco la frequenza massima dei valori che compaiono più spesso
    freq_max = conteggio[0];
    for(i = 1; i < 10; i++) {
        if(conteggio[i] > freq_max) {
            freq_max = conteggio[i];
        }
    }

    // stampo tutti i valori che compaiono con frequenza massima
    printf("I valori che compaiono con frequenza massima (%d volte) sono:\n", freq_max);
    for(i = 0; i < 10; i++) {
        if(conteggio[i] == freq_max) {
            printf("%d ", i);
        }
    }
    printf("\n");


    return 0;
}



int leggiNumero(int min, int max)
{
    int n;
    do {
        printf("Inserisci un numero tra %d e %d\n", min, max);
        scanf("%d", &n);
    } while(n < min || n > max);

    return n;
}