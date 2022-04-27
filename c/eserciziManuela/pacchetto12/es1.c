//
// Created by Mattia Lunardi on 15/04/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct nodo {
    int dato;
    struct nodo *pre;
    struct nodo *suc;
};

typedef struct nodo elem;
typedef elem *lista;

lista insert(int val, lista l);
elem *lalloc();
void swap(elem *a, elem *b);

int main(int argc, char **argv){


}

lista insert(int val, lista l){
    elem *p, *cur, *pre;
    pre = NULL;
    cur = l;
    while(cur != NULL && val > cur->dato){
        pre = cur;
        cur = cur->suc;
    }

    if(cur == NULL || val != cur->dato){
        p = lalloc();
        p->dato = val;
        p->suc = cur;
        p->pre = pre;
        if(cur != NULL)
            cur->pre = p;
        if(pre != NULL)
            pre->suc = p;
        else
            l = p;
    }
    return l;
}


elem *lalloc(){
    return (struct nodo *)malloc(sizeof(struct nodo));
}