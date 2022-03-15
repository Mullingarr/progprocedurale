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

typedef struct autore{
    char nome[50];
    char cognome[50];
    int annoNascita;
}Autore;

typedef struct libro{
    int isbn[13];
    char titolo[50];
    int annoPubblicazione;
    int codiceScaffale;
    float prezzo;
    Autore *autore;
    struct libro *next;
    struct libro *prev;
}Libro;

Libro *head = NULL; //primo elemento della lista dei libri
Libro *tail = NULL; //ultimo elemento della lista dei libri
Libro *mid = NULL; //elemento che si trova +/- a meta della lista

void printBooks(int);
void printBook(Libro *);
Libro *bookAlloc(void);
Libro readBook(void);

int main(){



}

/**
 * Alloca lo spazio necessario a contenere una struct di tipo libro
 */
Libro *bookAlloc(void){
    return (struct libro *) malloc(sizeof(struct libro));
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

void printBook(Libro *libro){
    printf("Titolo libro: %s\n", libro->titolo);
    printf("Autore: %s %s\n", libro->autore->nome, libro->autore->cognome);
    printf("Anno pubblicazione %d\n", libro->annoPubblicazione);
    //printf("codice isbn ")
    printf("prezzo: %f\n", libro->prezzo);
}