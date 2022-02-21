//
// Created by Mattia Lunardi on 21/02/22.
//

/**
 * Esercizio 5
 * Scrivere un programma che legga un testo (max 100 caratteri) costituito da una sequenza di parole
 * separate da ',' senza spazi. Il programma deve poi contare il numero di parole e il numero medio
 * di caratteri per parola.
 * Esempio: "ciao, casa, sta, tutto, vero" --> 5 parole, media caratteri 4
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char testo[1001];
    int i,n,virgole=0;

    printf("Inserire le parole: ");
    scanf("%s",testo);
    n = strlen(testo);

    for (i=0; i<n; i++)
    {
        if (testo[i]==',')
            virgole++;
    }

    printf("Il numero di parole e' %d\n",virgole+1);
    printf("La media dei caratteri per parole e' %f\n", (n-virgole)/(virgole+1.0));


    return 0;
}