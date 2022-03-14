//
// Created by Mattia Lunardi on 14/03/22.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXCHARS 100

typedef struct node{
    int pos;
    int value;
    struct node *next;
} Node;

Node *head = NULL;

void printList();
void insert(Node *);
int length();
Node *deleteFirst();
Node *nodeAlloc();

int main(){

    head = nodeAlloc();
    head->value = 10;
    head->pos = 0;
    head->next = NULL;

    printf("Creazione della lista!\n");
    for(int i = 0; i < 5; i++){
        Node *tmp = nodeAlloc();
        printf("inserisci valore\n>");
        scanf("%d", &tmp->value);
        insert(tmp);
    }

    printList();
    Node *first = deleteFirst();
    printf("first:\n");
    printf("(%d,%d)\n", first->pos, first->value);

    printf("After deletion\n");
    printList();

}

Node *nodeAlloc(){
    return (struct node *) malloc(sizeof(struct node));
}

void printList(){
    Node *ptr = head;
    while(ptr != NULL){
        printf("(%d,%d)\n", ptr->pos, ptr->value);
        ptr = ptr->next;
    }
}

void insert(Node *node){
    //puntatore alla vecchia testa
    node->next = head;
    node->pos = head->pos + 1; //aggiornamento della posizione
    //puntatore alla nuova testa
    head = node;
}

/**
 * Elimina il primo item
 */
Node *deleteFirst(){
    //salvo riferimento al primo item
    Node *tmp = head;
    //assegno next come nuova testa
    head = head->next;
    //ritorno la vecchia testa
    return tmp;
}

int length(){
    int length = 0;
    for(Node *current = head; current != NULL; current = current->next)
        length++;

    return length;
}

/**
 * Navigo la lista finche' non trovo un nodo con il valore passato e lo elimino
 * @param value
 * @return
 */
Node *delete(int value){
    //parto dal primo nodo
    Node *current = head;
    Node *previous = NULL;
    if(head == NULL) return NULL; //se lista vuota
    while(current->value != value){ //navigo la lista
        if(current->next == NULL) return NULL; //ultimo elemento della lista
        else{
            previous = current;
            //avanti di un nodo
            current = current->next;
        }
    }
    //ho trovato il nodo che cercavo
    if(current == head){
        head = head->next; //cambio la testa in modo che punti alla successiva
    }else{
        previous->next = current->next;
    }
    return current;
}
