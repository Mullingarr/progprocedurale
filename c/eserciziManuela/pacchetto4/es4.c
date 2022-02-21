//
// Created by Mattia Lunardi on 21/02/22.
//

/**
*   Esercizio 4
 *   Scrivere programma che chiede all'utente di inserire delle stringhe (senza spazi,
 *   di lunghezza al max 100). Il programma termina non appena l'utnete inserisce la stringa
 *   "stop", stampando il numero di stringhe inserite dall'utente di lunghezza I (dove I e'
 *   a sua volta inserito dall'utente all'inizio del programma)
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    int l, cont=0;
    char stringa[MAX+1];

    printf("Inserire l: ");
    scanf("%d",&l);

    do
    {
        printf("Inserire stringa: ");
        scanf("%s",stringa);

        if (strlen(stringa)==l)
            cont++;

    } while (strcmp(stringa,"stop")!=0);

    // elimino la parola "stop" dal conteggio quando l=4
    if (l==4)
        cont --;

    printf("Numero di stringhe lunghe %d e' %d\n", l, cont);
    return 0;
}
