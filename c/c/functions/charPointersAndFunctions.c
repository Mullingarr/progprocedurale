//
// Created by Mattia Lunardi on 10/02/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strCpy(char *s, char *t);
void strCpyPointers(char *s, char *t);
void strCpyPointersSecondVersion(char *, char *);
void finalStrCpy(char *, char *);
void strCat(char *, char *);

int main(){
    char helloWorld[] = "HelloWorld";
    char otherString[] = "otherString";

    strCat( helloWorld, otherString);
    //printf("%s\n", helloWorld);

    return 0;
}

void strCpy(char *s, char *t){
    int i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

void strCpyPointers(char *s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

void strCpyPointersSecondVersion(char *s, char *t){
    while((*s++ = *t++) != '\0') ;
}

void finalStrCpy(char *s, char *t){
    while((*s++ = *t++)) ;
}

/**
* Exercise 5 - 3
 * strcat(s, t): copies the string t to the end of s
*/

void strCat(char *s, char *t){


}

/**
* Exercise 5 - 4
 * Write the function strend(s, t), which returns 1 if the string t occurs at the end of the string s
 * and zero otherwise.
*/