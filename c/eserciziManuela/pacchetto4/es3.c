//
// Created by Mattia Lunardi on 21/02/22.
//

/**
* Esercizio 3
 * Scrivere un programma che legga in ingresso un array di interi positivi
 * (inserimento termina con l'inserimento di un valore <= 0) e di dimensione
 * massima 100 e ne inverte la posizione degli elementi
*/

#include <stdio.h>
#define DIM 100

int main()
{
    int a[DIM],b[DIM],i,n;

    // Leggo l'array A (ipotizzando che sia una sequenza di interi
    // positiva non più lunga di DIM e terminata da un valore <=0)
    printf("\nInserisci l'elemento 0 dell'array a: ");
    scanf("%d",&a[0]);
    for (i = 1; i < DIM && a[i-1]>0; i++){
        printf("\nInserisci i valore %d per l'array a: ", i);
        scanf("%d",&a[i]);
    }

    //salvo la lunghezza effettiva dell'array
    if(a[i-1] <= 0)
        n = i-1;
    else
        n = i;

    //copio a in b
    for (i=0; i<n; i++)
        b[i] = a[i];

    //inverto a
    for (i=0; i<n; i++)
        a[i] = b[n-i-1];

    for (i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}