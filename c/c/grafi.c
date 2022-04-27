//
//  main.c
//  Grafi
//
//  Created by paolo massazza on 29/03/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{
    int nome;
    struct nodo * next;
};

typedef struct nodo NODO;


/*
 AllocaMat riceve in ingresso un intero che rappresenta
 l'ordine della matrice (quadrata) da creare. La funzione restituisce
 l'indirizzo base di un vettore di ord puntatori i cui valori
 sono gli indirizzi base di ciascuna riga della matrice (vettore di ord interi)
 */

int **AllocaMat(int ord){
    int i;
    int * * mat;
    /* alloca un vettore di puntatori */
    mat = (int **)malloc(ord*sizeof(int*));
    for(i=0;i<ord;i++)    /* alloca la riga i-esima */
        mat[i] =(int *)malloc(ord*sizeof(int));
    return mat;
}

int **EliminaMat(int **mat, int ord){
    int i;
    for(i=0;i<ord;i++)
        free(mat[i]); /* cancella la riga i-esima */
    free(mat);
    return NULL;
}

void StampaMat(int **mat, int ord){
    int i,j;
    for (i=0;i<ord;i++){
        for(j=0;j<ord;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}

/* Costruisce un grafo denso non orientato con n nodi
 e un numero di archi pari circa a c/100 il numero massimo */

void MatRand(int **mat,int n,int c){
    int i,j,nmax;
    float soglia, k;
    nmax=(n*(n-1))/2;
    soglia=c/100.0;
    srand(time(NULL)%1000000);
    for(i=0;i<n;i++){
        mat[i][i]=0;
        for(j=i+1;j<n;j++){
            k=rand()%nmax;
            mat[i][j] = mat[j][i]=(k<soglia*nmax)?1:0;}
    }
}

/* Costruisce un grafo sparso non orientato con n nodi
 e un numero di archi pari a c*n */

void MatRandSparsa(int **mat,int n,int c){
    int i,j,nlati;
    nlati=c*n;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            mat[i][j]=mat[j][i]=0;
    srand(time(NULL)%1000000);
    while(nlati>0){
        i=rand()%n;
        j=rand()%n;
        if ((i!=j)&&(!mat[i][j])){
            mat[i][j]= mat[j][i]=1;
            nlati--;
        }
    }
}

void MatMan(int **mat,int n){
    int i,j,a;
    for(i=0;i<n;i++){
        mat[i][i]=0;
        for(j=i+1;j<n;j++){
            printf("Esiste un arco da %d a %d (0/1)?",i+1,j+1);
            scanf("%d",&a);
            mat[i][j] = (mat[j][i]=((a)?1:0));
        }
    }
}

/*
 CreaGrafo riceve in ingresso una matrice di adiacenza di ordine dim
 e costruisce la rappresentazione del grafo basata su liste di adiacenza,
 restituendo l'indirizzo base di un vettore di puntatori alle liste di
 adiacenza di ciascun nodo (uso di nodi fittizi in testa)
 */

NODO ** CreaGrafo(int **MatAdiac, int dim){
    int i,j;
    NODO *pt;
    NODO ** grafo;
    grafo =(NODO**) malloc(dim*sizeof(NODO*));
    for (i=0;i<dim;i++){
        grafo[i]=(NODO *)malloc(sizeof(NODO)); //nodi fittizi
        grafo[i]->nome=0;
        grafo[i]->next=NULL;
    }
    for (i=0;i<dim;i++){
        pt=grafo[i];
        for (j=0;j<dim;j++)
            if (MatAdiac[i][j] != 0){
                pt->next=(NODO *)malloc(sizeof(NODO));
                pt->next->nome=j+1;
                pt->next->next=NULL;
                pt = pt->next;
            }
    }
    return grafo;
}

NODO **EliminaGrafo(NODO **grafo, int dim){
    int i;
    NODO *pt, *pt1;
    for (i=0;i<dim;i++){
        pt1=grafo[i];
        while (pt1!=NULL){
            pt=pt1;
            pt1=pt1->next;
            free(pt);
        }
    }
    free(grafo);
    return NULL;
}

void StampaGrafo(NODO ** grafo, int ord){
    int i;
    NODO * pt;
    for (i=0;i<ord;i++){
        pt=grafo[i]->next;
        while(pt!=NULL){
            printf("arco da %d a %d\n",i+1,pt->nome);
            pt=pt->next;
        }
    }
}

void visita(int nodo){printf("%d\n",nodo);}

/**
 * @recursive
 */
void ProfondRic(NODO ** grafo,int nodo,int * visitato){
    NODO *pt;
    visita(nodo);
    visitato[nodo-1] = 1;
    for (pt = grafo[nodo-1]->next; pt!=NULL; pt=pt->next)
        if (visitato[pt->nome-1] == 0)
            ProfondRic(grafo,pt->nome,visitato);
}

int main(void)
{int i,j,n,d;
    int ** mat=NULL;
    NODO ** grafo=NULL;
    int *visitato=NULL;
    do {
        printf("Che cosa vuoi fare (1=crea,2=stampa,3=visita,4=elimina,5=esci)?");
        scanf("%d",&i);
        switch(i){
            case 1: if (mat!=NULL) printf("Attenzione grafo esistente\n");
            else
            {printf("Inserisci il numero dei nodi ->"); scanf("%d",&n); printf("\n");
                printf("Costruzione del grafo (1=manuale, 2=automatica (denso), 3=automatica (sparso))");
                scanf("%d",&i); printf("\n");
                mat=AllocaMat(n);
                switch(i){
                    case 1: MatMan(mat,n); break;
                    case 2: printf("Inserisci una percentuale (0-100) ->");
                        scanf("%d",&d); printf("\n");
                        MatRand(mat,n,d); break;
                    case 3: printf("Inserisci una costante (0-%d) ->",(n-1)/2);
                        scanf("%d",&d); printf("\n");
                        MatRandSparsa(mat,n,d);
                }
                grafo=CreaGrafo(mat,n);
            }
                break;
            case 2: if (mat==NULL) printf("Attenzione grafo non esistente\n");
            else
            {printf("Tipo stampa (0=matrice,1=lista)? "); scanf("%d",&d);
                if (d)
                {printf("Liste di adiacenza del grafo\n");StampaGrafo(grafo,n);}
                else
                {printf("Matrice di adiacenza del grafo\n");StampaMat(mat,n);}
            }
                break;
            case 3: if (mat==NULL) printf("Attenzione grafo non esistente\n");
            else
            {visitato=(int *)malloc(n*sizeof(int));
                for(j=0;j<n;j++) visitato[j]=0;
                printf("nodo sorgente (1,..,%d)?",n); scanf("%d",&d);
                printf("Sequenza dei nodi visitati in profondita'\n");
                ProfondRic(grafo,d,visitato);}
                break;
            case 4: if (mat!=NULL) mat=EliminaMat(mat,n);
                if (grafo!=NULL) grafo=EliminaGrafo(grafo,n);
                if (visitato!=NULL) {free(visitato); visitato=NULL;}
                break;
            case 5: ;
        }
    } while (i!=5);
    return(0);
}
