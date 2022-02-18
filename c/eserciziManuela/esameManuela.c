//
// Created by Mattia Lunardi on 17/02/22.
//

#include <stdlib.h>
#include <stdio.h>

#define MAXRIGHE 10
#define MAXCOLONNE 10

//ESERCIZIO 1

int **fill_matrix(int rows, int cols);
void free_matrix(int **, int);
void print_matrix(int **, int, int);
/**
* Si consideri una matrice di valori interi positivi in cui ogni elemento rappresenta la quota
 * del terrono nell'area di un vulcano. Quando il vulcano erutta il cratere si apre ed esce la
 * lava, per cui la sua quota cresce di 2 unita' e la lava che fuoriesce fa crescere di 1 anche
 * la quota delle otto posizioni attorno al vulcano, se hanno un quota inferiore a quella
 * del vulcano prima dell'eruzione (la lava puo' solo scendere).
 *
*/

/**
* Esercizio A
 * Scrivere una funzione che, ricevuti in ingresso una matrice di interi, la posizione del vulcano
 * che erutta e qualsiasi altro parametro ritenuto strettamente necessario, aggiorna la matrice a
 * seguito dell'eruzione del vulcano, secondo le regole sopra descritte.
 * Nota:
 * Nel caso le coordinate del vulcano non siano valide, la funzione non fara' nulla. Si ipotizzi
 * che il numero di righe e colonne della matrice siano 2 costanti NR ed NC definite attraverso
 * la direttiva #define
*/

void erutta(int **matrix,const int *pos_x,const int *pos_y){
    //calcolo delle posizioni da aggionare
    int north = *pos_y - 1;
    int south = *pos_y + 1;
    int east = *pos_x + 1;
    int west = *pos_x - 1;
    //gli angoli sono una combinazione di questi
    //aggiornamento delle posizioni
    matrix[*pos_y][*pos_x] = matrix[*pos_y][*pos_x] +=1;
    matrix[north][*pos_x] = matrix[north][*pos_x] +=1;
    matrix[south][*pos_x] = matrix[south][*pos_x] +=1;
    matrix[*pos_y][west] = matrix[*pos_y][west] +=1;
    matrix[*pos_y][east] = matrix[*pos_y][east] +=1;
    //aggiornamento angoli
    matrix[north][east] = matrix[north][east] +=1;
    matrix[north][west] = matrix[north][west] +=1;
    matrix[south][east] = matrix[south][east] +=1;
    matrix[south][west] = matrix[south][west] +=1;
}

/**
* Esercizio B
 * Scrivere un programma che chiede all'utente i dati per popolare la matrice e le coordinate di
 * un vulcano. Il programma, quindi, richiamera' la funzione definita al punto precedente e
 * stampera' a video il contenuto della matrice dopo l'eruzione.
*/

/**
* Matrice Esempio
 * Prima eruzione
 *
 * 3,0,6,1,5,1,5,6,8,1
 * 0,0,5,[6],0,5,4,0,5,6
 * 1,0,8,1,2,6,4,6,5,6
 * 5,1,8,6,0,0,0,0,0,0
 * 3,1,3,0,4,1,2,1,5,6
 * 5,1,5,1,3,1,1,0,7,1
 * 5,1,5,1,0,0,5,6,2,3
 * 3,1,8,1,0,0,0,0,0,0
 *
 * Dopo eruzione
 *
 * 3,0,[6],[2],[6],1,5,6,8,1
 * 0,0,[6],[8],[1],5,4,0,5,6
 * 1,0,[8],[2],[3],6,4,6,5,6
 * 5,1,8,6,0,0,0,0,0,0
 * 3,1,3,0,4,1,2,1,5,6
 * 5,1,5,1,3,1,1,0,7,1
 * 5,1,5,1,0,0,5,6,2,3
 * 3,1,8,1,0,0,0,0,0,0
*/

int main(int argc, char *argv[]){
    int **matrix;
    int rows, cols;
    int centroVulcano_x;
    int centroVulcano_y;
    if(argc < 5)
        printf("Not enough arguments");
    else{
        rows = atoi(argv[1]);
        cols = atoi(argv[2]);
        centroVulcano_x = atoi(argv[3]);
        centroVulcano_y = atoi(argv[4]);

        //prova con matrice 3x3
        matrix = fill_matrix(rows, cols);
        print_matrix(matrix, rows, cols);
        printf("---Eruzione---\n");
        erutta(matrix, &centroVulcano_x, &centroVulcano_y);
        print_matrix(matrix, rows, cols);
        free_matrix(matrix, rows);
    }

}

int **fill_matrix(int rows, int cols){
    //allocazione matrice
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for(int row = 0; row < rows; row++)
        matrix[row] = (int *) malloc(cols * sizeof(int));

    //lettura valori
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("[%d][%d] -> ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

void free_matrix(int **matrix, int rows){
    for(int row = 0; row < rows; row++)
        free(matrix[row]);
    free(matrix);
}

void print_matrix(int **matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(j == cols-1)
                printf("[%d]\n", matrix[i][j]);
            else
                printf("[%d]", matrix[i][j]);
        }
    }
}