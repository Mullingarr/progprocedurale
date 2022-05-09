#include "stdio.h"
#include "stdlib.h"
#define LENGTH 10
struct nodo{
    int el;
    struct nodo *next;
};

typedef struct nodo *lista;

void shift(lista *);
void size(lista *);
void push_list(lista, lista);
lista remove_from_list(lista, int);
void print_list(lista *);
struct nodo *alloc_nodo();

int main(int argc, char *argv[]){
    lista head_list = alloc_nodo();

    int valori[LENGTH] = {10, 20, 30 ,40, 50, 60, 70, 80, 90, 100};
    lista copia_testa = head_list;
    for(int i = 0; i < LENGTH; i++){
        printf("creazione nodo %d, valore: %d\n", i, valori[i]);
        copia_testa->el = valori[i];
        if(i < LENGTH-1){
            copia_testa->next = alloc_nodo();
            copia_testa = copia_testa->next;
        }
    }

    lista *list = &head_list;
    print_list(list);
    shift(list);
    printf("================\n");
    print_list(list);
    printf("================\n");
    shift(list);
    print_list(list);

}

/**
 * Riceve in ingresso la testa di una lista l. La funzione deve modificare la lista l
 * spostando tutti i nodi in avanti di una posizione: il primo nodo diventa il secondo,
 * il secondo diventa il terzo e così via. L'ultimo nodo della lista diventa il primo nodo.
 * Nel caso la lista sia vuota o contenga un solo elemento, la funzione non farà niente.
 * @param l 
 */
void shift(lista *l){
    if(l == NULL) return;
    lista head = *l;
    if(head == NULL) return;
    if(head->next == NULL) return;

    lista curr = head->next;
    lista prev = head;

    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    curr->next = head;
    *l = curr;

}

void print_list(lista *l){
    size_t index = 0;
    lista head = *l;
    while(head != NULL){
        printf("[%zu, %d]\n", index, head->el);
        head = head->next;
        index++;
    }

}

void push_list(lista testa, lista nodo_da_aggiungere){
}

lista remove_from_list(lista testa, int valore){
}

void size(lista *head){
}

struct nodo *alloc_nodo(){
    return (struct nodo *) malloc(sizeof(struct nodo));
}