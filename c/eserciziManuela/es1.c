//
// Created by Mattia Lunardi on 11/02/22.
//

#include <stdio.h>
#include <stdbool.h>

/**
* es 1:
 * Scrivere un programma che chieda all'utente di inserire un numero intero n non negativo
 * e poi legga una lista di interi lunga n. Finito l'inserimento della lista il programma stampa a video
 * la somma dei numeri inseriti.
*/


int somma(){
    int somma = 0;
    int letto;
    do{
        scanf("%d", &letto);
        if(letto < 0) somma += letto;
    }while(letto != 0);
    return somma;
}
/**
*  Esercizio 2:
 *  Scrivere un programma che chieda all'utente di inserire una lista di numeri, di lunghezza
 *  non specificata e terminata da 0.
 *  Terminato l'inserimento il programma stampa la somma di tutti i numeri negativi che sono
 *  stati inseriti.
*/

int sommaNegativi(){
    int somma = 0;
    int letto;
    do{
        scanf("%d", &letto);
        if(letto < 0) somma += letto;
    }while(letto != 0);
    return somma;
}

/**
* Esercizio 3:
 * Scrivere un programma che chieda all'utente di inserire un intero positivo n e poi calcoli e
 * stampi a video il fattoriale di n
*/


int factorial(){
    unsigned int n, i;
    unsigned int fattoriale = 1;
    scanf("%d", &n);
    for(int i = n; i > 1; i--) fattoriale += i;

    return fattoriale;
}

/**
* Esercizio 4:
 * Scrivere un programma che chieda all'utente di inserire un numero intero n non negativo
 * e poi stampi a video n-esimo elemento della successione di Fibonacci
*/

int fib(){
    unsigned int n, i, fib, prec, precPrec;
    scanf("%u", &n);
    if (n == 0 || n == 1)
    {
        printf("F(%u) = %u\n", n, 1);
        return 0;
    }

    prec = 1;
    precPrec = 1;
    for (i = 2; i <= n; i++)
    {
        fib = prec + precPrec;
        //printf("F(%u) = %u\n", i, fib);
        precPrec = prec;
        prec = fib;
    }
    printf("F(%u) = %u\n", n, fib);
    return 0;
}


/**
* Esercizio 5
 * Scrivere un programma che chieda all'utente di isnerire una sequenza di numeri positivi,
 * di lunghezza non specificata a priori e terminata da zero. Quando l'utente inserisce uno zero,
 * il programma stampa a video "crescente" se la successione inserita (escluso lo zero che termina
 * la successione) e' strettamente crescente, "decrescente" se la successione e' descrescente (escluso lo
 * zero finale), oppure "Non crescente e Non descrescente" se nessuno dei altri casi e' verificato
*/

void seq(){
    unsigned int letto, precedente;
    int crescente = 1, decrescente = 1;
    unsigned int iterazione = 0;

    while (true)
    {
        scanf("%u", &letto);

        if (letto == 0)
            break;

        iterazione++;

        if (iterazione > 1)
        {
            if (letto >= precedente)
                decrescente = 0;

            if (letto <= precedente)
                crescente = 0;
        }
        precedente = letto;
    }

    if (iterazione <= 1)
    {
        crescente = 0;
        decrescente = 0;
    }

    if (crescente)
        printf("CRESCENTE\n");
    else if (decrescente)
        printf("DECRESCENTE\n");
    else
        printf("NON CRESCENTE E NON DECRESCENTE\n");
}
/**
* Esercizio 3:
 * Scrivere un programma che chieda all'utente di inserire un intero positivo n e poi calcoli e
 * stampi a video il fattoriale di n
*/

int fibonacci(int n){
    if(n == 0 || n == 1)
        return 1;
    else{
        return (n - 1) + (n - 2);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int fattoriale = 1;

    for(int i = 1; i < n; i++){
        fattoriale *= i;
    }

    printf("fattoriale : %d\n", fattoriale);


    int v[10];
    for(int i = 0; i < 10; i++){
        if(i < 9){

        }
    }
}