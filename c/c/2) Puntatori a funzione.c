//
//  main.c
//  LezC
//
//  Created by admin on 09/03/20.
//  Copyright © 2020 admin. All rights reserved.
//

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n, int (*comp)(int,int))
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        // trova il minimo elemento nel vettore
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (comp(arr[j],arr[min_idx]))
                min_idx = j;
        // scambia il minimo trovato con il primo elemento
        swap(&arr[min_idx], &arr[i]);
    }
}

int minore(int a,int b) {return (a<b)?1:0;}

int maggiore(int a,int b) {return (a<b)?0:1;}

int main(int argc, const char * argv[]) {
    int i;
    int v[]={3,1,5,2,7,4,6,9,8};
    int (*ptrfun)(int,int);
    
    ptrfun=minore;
    selectionSort(v,9,ptrfun);
    for (i=0; i<9; i++) {
        printf("v[%d]=%d\n",i,v[i]);
    }
    return 0;
}
