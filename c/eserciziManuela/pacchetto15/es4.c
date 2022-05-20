//
// Created by Manuela on 19/05/2022.
//

/*
 * Supponete di usare la seguente struttura per implementare liste concatenate,
 *      struct nodo{char c; struct nodo *next;};
 * Definite una procedura che riceve in ingresso una stringa v(un vettore di caratteri),
 * e restituisce una lista di pari lunghezza contenente gli stessi caratteri nello stesso ordine.
 */

#include "stdio.h"
#include "stdlib.h"

struct nodo{
    char c;
    struct nodo *next;
};
typedef struct nodo *lista;

lista alloc_nodo();
int lunghezza_stringa(char *str);
char carattere(char *str, int i);


int main(int arcg, char *argv[]){
    char *v = argv[1];
    lista *head= (struct nodo**)malloc(sizeof(struct nodo));
    int v_length = lunghezza_stringa(v);
    printf("lunghezza stringa %d\n",v_length);
    for(int i=0; i<v_length; i++){
        lista new_node = alloc_nodo();
        new_node->c = carattere(v, i);
        new_node->next = NULL;
        (*head)->next = new_node;
        (*head)= (*head)->next;
    }
    while((*head)->next != NULL){
        printf("%c\n", (*head)->c);
    }

    return 0;
}

lista alloc_nodo(){
    return (struct nodo*)malloc(sizeof(struct nodo));
}

int lunghezza_stringa(char *str){
    int i=0;
    int p=0;
    while(str[i]!='\0'){
        p++;
    }
    return p;

}

char carattere(char *str, int i){
    if(str[i] != '\0'){
        return str[i];
    }
    return '\0';
}

