//
//  main.c
//  Stack
//
//  Created by paolo massazza on 22/03/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#undef N
#define N 10
#undef ERR
#define ERR -0

typedef unsigned ITEM;

struct nodo {ITEM el; struct nodo * succ;};
typedef struct nodo NODO;

struct stack {struct nodo * top;};
typedef struct stack STACK;

void Init_stack(STACK * pt){pt->top=NULL;}

int Is_empty(STACK * pt){return (pt->top==NULL);}

ITEM Top(STACK * pt){
    if (Is_empty(pt)) return ERR;
    else return pt->top->el;
}

int Push(STACK * pt, unsigned el){
    NODO * ptr;
    if ((ptr=malloc(sizeof(NODO)))==NULL) return ERR;
    else{
        ptr->el=el;
		printf("Indirizzo del nodo: %p\n", ptr);
		printf("Indirizzo di ptr: %p\n", &ptr);
		ptr->succ=pt->top;
        pt->top=ptr;
        return 0;
    }
}

int Pop(STACK * pt){
    NODO * ptr;
    if (Is_empty(pt)) return ERR;
    else {
        ptr=pt->top;
        pt->top = pt->top->succ;
        free(ptr);
        return 0;
    }
}

int main(void){
    STACK *st; int i;
    ITEM val;
    st=malloc(sizeof(STACK));
    Init_stack(st);
    i=10;
    while(i){
        printf("immetti un valore: ");
        scanf("%u",&val);
        printf("\n");
        Push(st,val);
        i--;
    }
    while(!Is_empty(st)){
        printf("%u\n",Top(st)); Pop(st);
    }
    return 0;
}
