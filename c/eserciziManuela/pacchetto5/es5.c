//
// Created by Mattia Lunardi on 07/03/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR 1.0 //percentuale di approsimazione

/**
 * Esercizio 1 - Triangoli e rettangoli
 * Si definiscano 2 tipi di dato adatti a rappresentare triangoli generici e rettangoli con i lati paralleli
 * agli assi:
 * Un triangolo sia definito come 3 punti nel piano
 * Un rettangolo con i lati paralleli agli sia invece definito da una coppia di punti: il suo vertice in alto
 * a sinistra (NO, NordOvest) e il suo vertice in basso a destra (SE, SudEst)
 */

typedef struct point{
    float x;
    float y;
    char modello[10];
} Point;

typedef struct vertex{
    Point p1;
    Point p2;
} Vertex;

typedef struct triangle{
    Point x;
    Point y;
    Point z;
} Triangle;

typedef struct rectangle{
    Vertex v1; //NO
    Vertex v2; //SE
} Rectangle;

float distanza(Point *, Point *);
int degenere(Triangle *);
int pseudouguali(float, float);
float erone(float, float, float);
void printTriangle(Triangle *);

/**
 * Esercizio 1a
 * Si scriva quindi un programma che stabilisca se un triangolo e':
 * "Ragionevolmente isoscele" - (pseudoisoscele)
 * "Ragionevolemente equilatero" - (pseudoequilatero)
 * Il programma deve verificare se valgono le relative proprieta' (lunghezza dei dati) a meno di una ragionevole
 * approssimazione in percentuale, da impostarsi come costante globale
 */

/**
 * Esercizio 1b
 * Si scriva un programma che, dati 2 rettangoli con i lati paralleli agli assi:
 * 1. Verifichi che i 2 rettangoli dati siano "corretti" - il vertice di NO sia effettivamente a NO rispentto
 * al vertice di SE
 * 2. Calcoli il loro rettangolo di inviluppo, definito successivamente
 * Calcoli, se esiste, il rettangolo di intersezione, oppure segnali che i rettangoli sono interamente non
 * sovrapposti, cioe' del tutto disgiunti.
 */

/**
 * Esercizio 2
 * Estendere esercizio 1b ad un numbero arbitrario di rettangoli (massimo 100) inseriti dall'utente
 */

int main(int argc, char **argv){
    Point p;
    p.x = 10;
    p.y = 11;
    printf("%f, %f\n", p.x, p.y);
    Point *p_toP = &p;
    p_toP->x = 20;
    p_toP->y = 22;

    printf("%f, %f\n", p.x, p.y);

    //Creazione del triangolo
    Point p1;
    p1.x = 31;
    p1.y = 32;

    Point p2;
    p2.x = 41;
    p2.y = 42;

    Triangle t;
    t.x = p;
    t.y = p1;
    t.z = p2;

    printTriangle(&t);

    printf(">");
    scanf("%s", p.modello);
    printf("%s", p.modello);

}


float distanza(Point *p1, Point *p2){
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrtf((dx * dx) + (dy * dy));
}

int degenere(Triangle *t){
    //Controllo che i punti non siano sovrapposti
    if(distanza(&t->x, &t->y) == 0 ||
       distanza(&t->x, &t->z) == 0 ||
       distanza(&t->y, &t->z) == 0)
        return 1;
    return 0;
}

int pseudouguali(float a, float b){
    float max, min;
    if(a == b) return 1;
    if(a * b == 0.0) return 0;
    min = a;max = b;
    if(min > max){
        min = b;
        max = a;
    }
    return (max - min) / max * 100 < ERROR;
}

float erone(float a, float b, float c){
    float p = (a+b+c) / 2;
    return sqrtf(p *(p-a) * (p-b) * (p-c));
}

void printTriangle(Triangle *t){
    printf("x: %f, %f\n", t->x.x, t->x.y);
    printf("y: %f, %f\n", t->y.x, t->y.y);
    printf("z: %f, %f\n", t->z.x, t->z.y);;
}