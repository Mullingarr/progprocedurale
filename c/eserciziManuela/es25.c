//
// Created by Mattia Lunardi on 11/02/22.
//

// Scrivere un programma che chieda all'utente di inserire una lista di numeri
// interi terminata da zero. Terminato l'inserimento degli input il programma
// stampa a video il minimo e il massimo dei numeri inseriti

#include <stdio.h>

int max(int a, int b);
int min(int a, int b);

int main()
{
    int letto;
    unsigned int numero_letti = 0;
    int MIN = 0, MAX = 0;
    int contatore = 0;
    do {
        scanf("%d", &letto);
        if (!letto)
        {
            break;
        }
        numero_letti++;
        if (numero_letti == 1)
        {
            MIN = letto;
            MAX = letto;
        }
        else
        {
            MIN = min(MIN, letto);
            MAX = max(MAX, letto);
        }
    } while(1);

    if (numero_letti == 0)
    {
        printf("non ho input, non posso calcolare\n");
    }
    else
    {
        printf("min = %d\n", MIN);
        printf("max = %d\n", MAX);
    }

    return 0;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
