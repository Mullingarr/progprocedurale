//
// Created by Mattia Lunardi on 11/02/22.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key{
    char *word;
    int count;
} keytab[] ={
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "void", 0,
        "while", 0
};

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

int main(){
    return 0;
}

/**
 * Finds the word in tab[0] ... tab[n - 1]
 * @param word
 * @param tab
 * @param n
 * @return
 */
struct key *binsearch(char *word, struct key *tab, int n){
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while(low < mid){
        mid = low + (high - low) / 2;
        if((cond = strcmp(word, mid -> word)) < 0) high = mid;
        else if(cond > 0) low = mid + 1;
        else return mid;
    }
    return NULL;
}