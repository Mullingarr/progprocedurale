//
// Created by Mattia Lunardi on 21/02/22.
//

/**
* Scrivere un programma che, letta una stringa  chiamata "testo" e una stringa chiamata
 * "ricercata" (max 200 caratteri). Poi verifichi se "ricercata" compare in "testo" e indicare
 * la posizione della prima occorrenza (nel caso ce ne fossero piu)
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char testo[201], ricercata[201];
    int l1, l2, trovata=0, i=0,j;

    printf("Inserire testo: ");
    scanf("%s",testo);

    printf("Inserire stringa da ricercare: ");
    scanf("%s",ricercata);

    l1 = strlen(testo);
    l2 = strlen(ricercata);

    while (l1-i >= l2 && trovata==0)
    {
        trovata=1;
        for (j=0; j<l2 && trovata==1; j++)
            if (testo[i+j]!=ricercata[j])
                trovata=0;
        i++;
    }

    if (trovata==0)
        printf("Non ho trovato %s in %s\n",ricercata,testo);
    else
        printf("Ho trovato %s in %s alla posizione %d\n",ricercata,testo,i-1);

    return 0;
}