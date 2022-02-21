//
// Created by Mattia Lunardi on 11/02/22.
//

#include <stdio.h>

typedef struct
{
    int anno;
    int pagine;
    char titolo[100];
    char  autore[30];
} libro;

libro leggi();
void stampa(libro l);

int main(void) {

    libro l1,l2;
    l1 = leggi();
    l2 = leggi();
    printf("\n Libro 1  \n\n");
    stampa(l1);
    printf("\n Libro 2  \n\n");
    stampa(l2);
    return 0;
}

libro leggi()
{
    libro l;
    scanf("%d%*c",&l.anno);
    scanf("%d%*c",&l.pagine);
    scanf("%[^\n]%*c",l.titolo);
    scanf("%[^\n]%*c",l.autore);
    return l;
}

void stampa(libro l)
{
    printf("Anno: %d\n",l.anno);
    printf("Pagine: %d\n",l.pagine);
    printf("Titolo: %s\n",l.titolo);
    printf("Autore: %s\n",l.autore);
}

void read(libro *l){
    scanf("%d%*c", &l->anno);
}