//
// Created by Mattia Lunardi on 11/02/22.
//

// Scrivere un programma che dato un numero intero positivo n stampi a video
// tutte le terne di numeri interi positivi a, b e c tali che:
// a*a + b*b = c*c
// 1 <= a,b <= n
#include <stdio.h>

int isTernaPitagorica(int a, int b, int c);

int main()
{
    int a, b, c, n;

    do
    {
        printf("Inserisci il valore di n: ");
        scanf("%d", &n);
    } while(n < 0);

    printf("Terne pitagoriche con 1 <= a,b <= n\n");

    for(a = 1; a <= n; a++)
    {
        for(b = 1; b <= n; b++)
        {
            for(c = 1; c <= 2*n; c++)
            {
                if(isTernaPitagorica(a, b, c))
                {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}

int isTernaPitagorica(int a, int b, int c)
{
    return a*a + b*b == c*c;
}