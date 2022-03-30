//
//  main.c
//  Traccia di una matrice
//
//  Created by paolo massazza on 18/03/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#undef DEBUG
#define DEBUG 1

unsigned short mat1[3][3];

unsigned short traccia(unsigned short ** mat, unsigned int ordine)
{ unsigned int tr=0, i;
    for(i = 0; i < ordine; i++)
        tr = tr + mat[i][i];
    return tr;
}

int main(int argc, const char * argv[]) {
    unsigned i,j,n;
    unsigned short * * mat;

    
    /*leggi l'ordine della matrice */
    printf("immetti l'ordine della matrice:");
    scanf("%d",&n);
    
    /* alloca un vettore di puntatori */
    mat = calloc(n,sizeof(unsigned short*));
    
    for(i=0;i<n;i++)    /* alloca la riga i-esima */
        mat[i] = calloc(n,sizeof(unsigned short));
    
    /* riempi la matrice con valori  casuali*/
    srand(time(NULL)%1000000);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            mat[i][j] = rand()%1000;
    
    /* stampa la matrice*/
    
#if DEBUG
    
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
            printf("%u ",mat[i][j]);
        printf("\n");}
   // printf("\n");
    
#endif
    
    /* stampa la traccia*/
    printf("\n");
    printf("La traccia della matrice è: %d\n",traccia(mat,n));
    
    //* attenzione alla chiamata sottostante, genera un errore in esecuzione, perché?
    printf("La traccia della matrice è: %d\n",traccia(mat1,3));
    return 0;
}
