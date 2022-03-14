//
// Created by Mattia Lunardi on 14/02/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

/**
 * qsort expects an array of pointers, two integers, and a function with two pointer
 * arguments.
 */
void qsort(void *lineptr[], int left, int right, int(* comp)(void *, void *));
int numcmp(char *, char *);


int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0;
    if(argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort((void **) lineptr, 0, nlines - 1,
        (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("input too big to sort\n");
        return 1;
    }
}

int numcmp(char *s1, char *s2){
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2) return -1;
    else if(v1 > v2) return 1;
    else return 0;
}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}