//
// Created by Mattia Lunardi on 21/02/22.
//

/**
 * Esercizio 1
 * Scrivere un programma che chieda all’utente di inserire due sequenze di N numeri ed esegua le seguenti operazioni:
    A.	dica quale dei due array ha valore medio più alto
    B.	calcoli l'array concatenato tra i due array in ingresso
    C.	trovi il massimo ed il minimo tra tutti i valori inseriti, indicando in quale dei due array sono presenti i due valori di massimo e minimo
    D.	stampi a video il loro prodotto scalare

    Prodotto scalare tra vettori - [a b c d e] * [f g h i l]' = af + bg + ch + di + el=
 */

#include <stdio.h>
#define DIM 5
int main()
{
    int i;
    int a[DIM];
    int b[DIM];
    int ab[2*DIM];
    float medio_a, medio_b;

    // Leggo l'array A
    for (i = 0; i < DIM; i++){
        printf("\nInserisci i valore %d per l'array a: ", i);
        scanf("%d",&a[i]);
    }

    // Stampo l'array A
    printf("\narray a = ");
    for (i = 0; i < DIM; i++)
        printf("%d ", a[i]);

    // Leggo l'array B
    for (i = 0; i < DIM; i++){
        printf("\nInserisci i valore %d per l'array b: ", i);
        scanf("%d",&b[i]);
    }

    // Stampo l'array B
    printf("\narray b = ");
    for (i = 0; i < DIM; i++){
        printf("%d ", b[i]);
    }
    printf("\n");

    // 2.1) VALOR MEDIO
    // ------------------------------------
    float somma = 0;
    for (i = 0; i < DIM; i++){
        somma += a[i];
    }
    medio_a = somma / DIM;

    // Calcolo valor medio di B
    somma = 0;
    for (i = 0; i < DIM; i++){
        somma += b[i];
    }
    medio_b = somma / DIM;

    if(medio_a == medio_b)
        printf("L'array a e l'array b hanno lo stesso valor medio.\n");
    else if (medio_a > medio_b)
        printf("L'array a ha valor medio piu' alto dell'array b.\n");
    else if (medio_a < medio_b)
        printf("L'array b ha valor medio piu' alto dell'array a.\n");

    // 2.2) CONCATENAZIONE
    // ------------------------------------
    for (i=0; i < DIM; i++){
        ab[i] = a[i];
    }
    for (i=0; i < DIM; i++){
        ab[i+DIM] = b[i];
    }

    // Stampo l'array AB
    printf("\narray a.b = ");
    for (i = 0; i < 2*DIM; i++){
        printf("%d ", ab[i]);
    }
    printf("\n");


    // 2.3) MAX e MIN
    // ------------------------------------
    // Inizializzo max e min con il primo valore dell'array
    int max = ab[0];
    int min = ab[0];
    int max_position = 0;
    int min_position = 0;

    for (i = 0; i < 2*DIM; i++){
        if (ab[i] > max){
            max = ab[i];
            max_position = i;
        }
        if (ab[i] < min){
            min = ab[i];
            min_position = i;
        }
    }


    if(max_position < DIM){
        printf("max = %d, in posizione %d nell'array a\n", max, max_position);
    }else{
        printf("max = %d, in posizione %d nell'array b\n", max, max_position-DIM);
    }

    if(min_position < DIM){
        printf("min = %d, in posizione %d nell'array a\n", min, min_position);
    }else{
        printf("min = %d, in posizione %d nell'array b\n", min, min_position-DIM);
    }

    // 2.4) PRODOTTO SCALARE DI DUE ARRAY
    // ------------------------------------
    int risultato = 0;
    for (i = 0; i < DIM; i++){
        risultato += a[i] * b[i];

    }
    printf("\nRisultato del prodotto scalare = %d", risultato);
    return 0;
}