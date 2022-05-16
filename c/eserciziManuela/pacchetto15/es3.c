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
void push_list_manu(lista*, lista);
lista remove_from_list(lista, int);
lista remove_from_list_manu(lista*, int);
void print_list(lista *);
struct nodo *alloc_nodo();

int main(int argc, char *argv[]){
    lista head_list = alloc_nodo();
    head_list->next = NULL;

    int valori[LENGTH] = {10, 20, 30 ,40, 50, 60, 70, 80, 90, 100};
    lista copia_testa = head_list;

    lista *curr = &head_list;


    for(int i = 0; i < LENGTH; i++){
        printf("creazione nodo %d, valore: %d\n", i, valori[i]);
        lista nodo = alloc_nodo();

        nodo->el = valori[i];
        nodo->next = NULL;
        push_list_manu(curr, nodo);

        copia_testa = copia_testa->next;
        curr = &copia_testa;

    }

    lista *list = &head_list;
    print_list(list);
   /* shift(list);
    printf("================\n");
    print_list(list);
    printf("================\n");
    shift(list);
    print_list(list);
*/
   return 0;
}

void push_list_manu(lista *l, lista nodo_da_aggiungere){
    lista head = *l;
    printf(" valore head pre while %d\n", head->el);
    while(head->next !=NULL){
        head = head->next;
    }
    head->next = nodo_da_aggiungere;

}

lista remove_from_list_manu(lista* l, int val_da_rimuovere){
    lista head = *l;
    while(head->next->el != val_da_rimuovere || head->next != NULL){
        head= head->next;
    }
    if(head->next == NULL) return NULL;
    if(head->next->el == val_da_rimuovere){
        if(head->next->next != NULL){
            lista tmp = head->next->next;
            lista risultato = head->next;
            head->next = tmp;
            return risultato;
        }else{
            lista risultato =head->next;
            head->next= NULL;
            return risultato;
        }

    }
    return NULL;
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
    lista copia_testa = testa;
    size_t index = 0;
    while(copia_testa->next != NULL){
        copia_testa = copia_testa->next;
        index++;
    }
    if(copia_testa->next == NULL){
        copia_testa->next = nodo_da_aggiungere;
        index++;
    }
    printf("aggiunto nodo a: [%zu], valore: [%d]\n", index, nodo_da_aggiungere->el);
}

lista remove_from_list(lista testa, int valore){
    lista copia_testa = testa;
    size_t index = 0;
    while(copia_testa->next != NULL || copia_testa->next->el == valore){
        copia_testa = copia_testa->next;
        index++;
    }
    if(copia_testa->next->el == valore){//ho trovato il nodo da rimuovere
        index++;
        if(copia_testa->next->next != NULL){
            lista tmp = copia_testa->next->next;
            lista ris = copia_testa->next;
            copia_testa->next = tmp;
            printf("Rimosso nodo a [%zu], con valore [%d]\n", index, valore);
            printf("Sostituito con il nodo a [%zu] con valore [%d]\n", index+1, valore);
            return ris;
        }else if(copia_testa->next->next == NULL){ //ultimo nodo
            lista ris = copia_testa->next;
            copia_testa->next = NULL;
            printf("Rimosso nodo a [%zu], con valore [%d]\n", index, valore);
            return ris;
        }
    }
    printf("Nessun nodo con valore [%d] trovato.\n", valore);
    return NULL;
}

void size(lista *head){
    //TODO
}

struct nodo *alloc_nodo(){
    return (struct nodo *) malloc(sizeof(struct nodo));
}