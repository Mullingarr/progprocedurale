//
//  main.c
//  Lista
//
//  Created by paolo massazza on 29/03/21.
//  Copyright © 2021 paolo massazza. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#undef DEBUG
#define DEBUG 1

typedef int TIPO;

struct nodo{
    TIPO dato;
    struct nodo * next;
};

typedef struct nodo NODO;
typedef NODO *LISTA;

/*
 Initlista restituisce un puntatore a un nodo allocato dinamicamente
 e che rappresenta la lista vuota (nodo fittizio)
 */

LISTA InitLista(void){
    LISTA tmp;
    tmp = (LISTA)malloc(sizeof(NODO));
    if(tmp==NULL) return NULL;
    tmp->next = NULL;
#if DEBUG
    printf("nodo fittizio creato all'indirizzo %p\n",tmp);
#endif
    return tmp;
}

/*
 Cancellalista percorre una lista a partire da un nodo puntato da pt
 eliminando un nodo dopo l'altro fino a quello in ultima posizione.
 L'istruzione pt->succ=CancellaLista(pt->succ) elimina la coda della lista
 a partire dal nodo successivo a quello puntato da pt (che diviene l'ultimo)
 */

LISTA CancellaLista(LISTA l){
    LISTA l1;
    while(l != NULL){
        l1 = l;
        l = l->next;  /* avanzo di un elemento */
        free(l1);     /* cancellando il precedente */
    }
    return NULL;
}

/* Accorcia(pt,pos) elimina l'elemento in posizione pos nella
 lista puntata da pt
 */

int Accorcia(LISTA l, int pos){
    int i;
    LISTA succ;
    if ((pos <= 0)||(l == NULL)) return -1; /* posizione errata o lista mancante*/
    succ = l->next;
    i = 0;
    while ((i<pos-1)&&(succ != NULL)){
        i++;
        l = succ;
        succ = succ->next;
    }
    if (succ==NULL) {printf("Attenzione: lista troppo corta\n");return -1;}  /* lista troppo corta */
    /* pt ora punta al nodo in posizione pos-1 che precede
     quello da eliminare (puntato da succ) */
    l->next = succ->next;
    free(succ);
    return 1;
}


int ElimInt(LISTA l,int i,int j){
    int k;
    LISTA t1,t2;
    if ((i<1)||(j<=i)||l==NULL) return -1; /* indici errati o lista mancante*/
    l = l->next;
    k = 1;
    while ((k<i)&&(l != NULL))
        k++; l = l->next;
    if (l==NULL){
        printf("Attenzione: lista troppo corta\n");return -1;
    }
    /* l ora punta al nodo in posizione i che precede
     quelli da eliminare (da i+1 a j-1)*/
    t1=l;
    t2=l->next; /* nodo i+1*/
    k++;
    if(t2==NULL) return 0; /*lista lunga i, nessuna cancelazione*/
    while((k<j)&&(t2!=NULL)){
        l=t2->next; free(t2);
        t2=l; k++;
    }
    if (t2==NULL) {
        t1->next=NULL;
        return 0;
    }
    else t1->next=t2;
    return 0;
}

/* Elimina(pt,el) ricerca l'elemento el in una lista puntata da pt
 e una volta trovato (la prima occorrenza) lo elimina dalla lista
 */

int Elimina(LISTA l, TIPO el){
    LISTA succ;
    if (l == NULL) return -1;
    succ = l->next;
    if (succ == NULL) return -1; /* lista vuota */
    while ((succ != NULL)&&(succ->dato!=el)){
        l = succ;  succ = succ->next;
    }
    if (succ==NULL) return -1;    /* fine lista l ora punta al nodo che precede quello da eliminare (puntato da succ)*/
    l->next = succ->next;
    free(succ);
    return 1;
}
/* Inserisci(l,pos,el) inserisce un elemento el in posizione pos
 nella lista l
 */
int Inserisci(LISTA l, int pos, TIPO el){
    int i;
    NODO* l1;
    i = 0;
    if (pos <= 0||l==NULL) return -1; /* posizione errata o lista mancante*/
    while ((i<pos-1)&&(l != NULL)){
        i++;l=l->next;
    }
    if (l==NULL) return -1; /*lista troppo corta*/
    /* l ora punta al nodo in posizione pos-1*/
    l1 = (NODO*)malloc(sizeof(NODO));
#if DEBUG
    printf("nodo creato all'indirizzo %p\n",l1);
#endif
    l1->next = l->next;
    l1->dato = el;
    l->next = l1;
    return 0;
}

/* Lunghezza(l) restuisce il numero di elementi nella lista l */
int Lunghezza(LISTA l){
    int i;
    if (l == NULL) {
        printf("Attenzione: lista mancante \n");
        return -1;
    }
    l = l->next;
    i = 0;
    while (l != NULL){
        l = l->next;
        i++;
    }
    return i;
}

int Stampa(LISTA l){
    if (l == NULL) {
        printf("Attenzione: lista mancante \n");
        return -1;
    }
    l = l->next;
    if (l == NULL) {
        printf("Attenzione: lista vuota\n");
        return -1;
    }
    printf("%d",l->dato);
    l = l->next;
    while (l != NULL){
        printf("->%d",l->dato);
        l = l->next;
    }
    printf("\n");
    return 0;
}

int main(void){
    char a;
    TIPO dato;
    int j;
    LISTA lista;
    lista=InitLista();
    do{
        printf("Che operazione vuoi eseguire (h=help)? ");
        scanf("%c",&a);
        printf("\n");
        switch(a){
            case 'h': printf("(h)elp\n");
                printf("(c)rea lista vuota\n");
                printf("(d)ealloca lista\n");
                printf("(l)unghezza della lista\n");
                printf("(i)nserisci un dato in una posizione specificata\n");
                printf("(s)tampa la lista\n");
                printf("(a)ccorcia la lista eliminando il dato in una posizione specificata\n");
                printf("(e)limina un dato specificato\n");
                printf("(t)ogli i nodi in un intervallo di posizioni\n");
                printf("(u)scita\n");
                break;
            case 'c': if (lista==NULL) lista = InitLista();
            else printf("Attenzione: lista esistente\n");
                break;
            case 'd': if (lista!=NULL) lista=CancellaLista(lista);
            else printf("Attenzione: lista  non definita\n");
                break;
            case 'l': if (lista!=NULL) printf("La lista contiene %d dati\n",Lunghezza(lista));
            else printf("Attenzione: lista  non definita\n");
                break;
            case 'i': if (lista==NULL) printf("Attenzione: lista  non definita\n");
            else {
                printf("inserisci un intero -> ");
                scanf("%d",&dato);
                printf("\n");
                printf("inserisci una posizione -> ");
                scanf("%d",&j);
                printf("\n");
                if (Inserisci(lista,j,dato)) printf("Attenzione posizione errata\n");}
                break;
            case 's': if (lista==NULL) printf("Attenzione: lista  non definita\n");
            else Stampa(lista);
                break;
            case 'a': if (lista==NULL) printf("Attenzione: lista  non definita\n");
            else{ printf("inserisci una posizione -> ");
                scanf("%d",&j);
                printf("\n");
                Accorcia(lista,j);}
                break;
            case 'e': if (lista==NULL) printf("Attenzione: lista  non definita\n");
            else{ printf("inserisci un intero -> ");
                scanf("%d",&dato);
                printf("\n");
                Elimina(lista,dato);}
                break;
            case 't': if (lista==NULL) printf("Attenzione: lista  non definita\n");
            else {
                printf("inserisci la prima posizione i -> ");
                scanf("%d",&dato);
                printf("\n");
                printf("inserisci la seconda posizione j -> ");
                scanf("%d",&j);
                printf("\n");
                ElimInt(lista,dato,j);}
                break;
            case 'u': if (lista!=NULL) lista=CancellaLista(lista);
                printf("Grazie e arrivederci\n");
                return 0;
            default: ;
        } /* fine switch */
        scanf("%c",&a);
    } while(a!='u');
    return 0;
}
