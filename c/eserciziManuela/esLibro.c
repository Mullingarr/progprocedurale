//
// Created by Mattia Lunardi on 15/03/22.
//

/**
 * Esercizio 4
 * Definire un tipo di dato che rappresenti un libro, in grado di contenere le seguenti informazioni:
 * * codice isbn
 * * autore
 * * titolo
 * * anno di pubblicazione
 * * Codice scaffale (numero intero)
 * * Prezzo
 *
 * Si definisca poi un tipo di dato in grado di rappresentare una libreria che puo' contenere
 * 100 libri e scrivere un programma che acquisisce i dati di N libri (con N letto da tastiera),
 * utilizzando la funzione descritta di seguito al punto A. Implementare anche le seguenti funzioni
 * A. una funzione che consente di acquisire da tastiera i dati di un singolo libro
 * B. una funzione che stampi i dati di un libro
 * C. una funzione che stampi i prezzi dei libri che si trovano in un certo scaffale
 * D. una funzione che stampi tutti gli autori, senza duplicati
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXLIBRI 100
#define MAX_ISBN 13

typedef struct autore{
    char nome[50];
    char cognome[50];
    int annoNascita;
}Autore;

typedef struct libro{
    char titolo[50];
    int annoPubblicazione;
    int codiceScaffale;
    float prezzo;
    int *isbn;
    Autore *autore;
    struct libro *next;
    struct libro *prev;
}Libro;

Libro *head = NULL; //primo elemento della lista dei libri
Libro *tail = NULL; //ultimo elemento della lista dei libri
Libro *mid = NULL; //elemento che si trova +/- a meta della lista
size_t lunghezza_lista = 0;

void printBooks(int);
void printBook(const Libro *);
Libro *bookAlloc(void);
Libro *readBook(void);
Autore *autoreAlloc(void);
int *readISBN(void);
Autore *readAutore(void);
void insertBook(Libro *);
Libro *deleteLibro(char *, int);
void swapHead(Libro *);
void swapTail(Libro *);
void swapMid(Libro *);

int main(){



}

Libro *readBook(void){
   Libro *book = bookAlloc();
   Autore *autore = autoreAlloc();
   printf("Inserisci informazioni libro!");
   printf("Titolo\n>");
   scanf("%s", book->titolo);
   printf("Anno pubblicazione\n>");
   scanf("%d", &book->annoPubblicazione);
   printf("Prezzo\n>");
   scanf("%f", &book->prezzo);
   printf("Codice Scaffale\n>");
   scanf("%d", &book->codiceScaffale);
   book->isbn = readISBN();
   book->autore = readAutore();
   return book;
}

int *readISBN(void){
    printf("Leggo isbn libro");
    int *isbn = (int *) malloc(MAX_ISBN * sizeof(int));
    for(int i = 0; i < MAX_ISBN; i++){
        printf("[%d]\n>", i);
        scanf("%d", &isbn[i]);
        printf("\n");
    }
    return isbn;
}

Autore *readAutore(void){
    printf("Inserisci dati autore\n");
    Autore *autore = autoreAlloc();
    printf("Autore del libro");
    printf("Nome\n>");
    scanf("%s", autore->nome);
    printf("Cognome\n>");
    scanf("%s", autore->cognome);
    printf("Anno nascita autore\n>");
    scanf("%d", &autore->annoNascita);
    return autore;
}


/**
 * Alloca lo spazio necessario a contenere una struct di tipo libro
 */
Libro *bookAlloc(void){
    return (struct libro *) malloc(sizeof(struct libro));
}

/**
 * Alloca lo spazio necessario a contenere una struct di tipo autore
 */
Autore *autoreAlloc(void){
    return (struct autore *) malloc(sizeof(struct autore));
}

/**
 * Printa i libri appartenenti ad un certo scaffale
 */
void printBooks(int codiceScaffale){
    Libro *current; //init pointer?
    if(mid->codiceScaffale >= codiceScaffale){
        //proseguo a controllare a destra
        current = mid;
        while(current->next != NULL){
            //ho raggiunto la fine
            if(current->next == tail) printf("DONE");
            else{ //aggiornamento pointer
               if(current->codiceScaffale == codiceScaffale) printBook(current);
               current = current->next;
            }
        }
    }else if(mid->codiceScaffale < codiceScaffale){
        //proseguo a controllare a sinistra
        current = mid;
        while(current->prev != NULL){
            //ho raggiunto la fine
            if(current->prev == head) printf("DONE");
            else{
                if(current->codiceScaffale == codiceScaffale) printBook(current);
                current = current->prev;
            }
        }
    }

}

void printBook(const Libro *libro){
    printf("Titolo libro: %s\n", libro->titolo);
    printf("Autore: %s %s\n", libro->autore->nome, libro->autore->cognome);
    printf("Anno pubblicazione %d\n", libro->annoPubblicazione);
    //printf("codice isbn ")
    printf("prezzo: %f\n", libro->prezzo);
}

/**
 * in base al parametro "codice scaffale" del libro
 * viene inserito nella giusta posizione nella lista.
 * Se esiste gia' un nodo con lo stesso codice, la lista
 * verrà "tagliata", inserito il nuovo nodo e infine
 * riallacciata
 */
void insertBook(Libro *daInserire){
    if(lunghezza_lista > 0){
        if(tail == NULL){
            tail = daInserire;
            lunghezza_lista++;
        }
        if(tail != NULL && mid == NULL){ //head e tail sono != NULL
           if(tail->codiceScaffale > daInserire->codiceScaffale){ //inserisco a destra, tail diventa mid
               Libro *oldTail;
               tail->next = daInserire;
               oldTail = tail;
               tail = daInserire;
               tail->prev = oldTail;
               tail->next = NULL;
               mid = oldTail;
               lunghezza_lista++;
           }else{
               mid = daInserire;
               mid->next = tail;
               mid->prev = head;
               lunghezza_lista++;
           }
        }
        if(mid != NULL){ //head e' sempre il primo che viene inizializzato
            int codice = daInserire->codiceScaffale;
            if(head->codiceScaffale >= codice && mid->codiceScaffale < codice){
                //cerco qui
                Libro *tmp = mid;
                while(tmp->prev->codiceScaffale > codice){
                    tmp = tmp->prev;
                }
                if(codice == tmp->codiceScaffale){ //match

                }
            }
            else if(mid->codiceScaffale >= codice && tail->codiceScaffale < codice){
                Libro *tmp = mid;
                while(tmp->next->codiceScaffale < codice){
                    tmp = tmp->next;
                }
                if(codice == tmp->codiceScaffale){ //match

                }
            }
        }
    }else{
        head = daInserire;
        printf("Libro inserito in testa\n");
    }
}

/**
 * Elimina la prima occorrenza del libro in base a titolo e codiceScaffale
 * @return il nodo eliminato
 */
Libro *deleteLibro(char *titolo, int codiceScaffale){

}


void swapHead(Libro *newHead){

}

void swapTail(Libro *newTail){

}

void swapMid(Libro *newMid){

}