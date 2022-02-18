//
// Created by Mattia Lunardi on 16/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXMOSSE 10

int main(){
    int c;
    while((c = getchar()) != EOF)
        putchar(tolower(c));
   return 0;
}


void esempio(){

    printf("1, 2, 3");
    int num;
    bool flag = false;
    int p = 0;
    int t;

    for(int i = 0; i < MAXMOSSE; i++){
        scanf("%d", &num);
        switch(num){
            case 1:
                p += 1;

                break;
            case 2:
                p*=2;
                break;
            case 3:
                p%=31;
                break;
        }
        if(p == t){
            printf("hai trovato il numero!");
            flag = true;
            break;
        }
    }
    if(flag == false)
        printf("hai perso!");
}


void es5(){
    int min = 0;
    int max = 0;
    int num;
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        if(num < min)
            min = num;
        else if(num > max)
            max = num;
    }


    for(int i = 0; i < 10; i++)
        printf("")
}

/**
* Exercise 7-1
 * Write a program that converts upper case to lower or lower case to upper,
 * depending on the name it is invoked with, as found in argv[0]
*/