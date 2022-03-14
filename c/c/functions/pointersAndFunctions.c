//
// Created by Mattia Lunardi on 10/02/22.
//
#include <stdio.h>
#include <ctype.h>

int getch(void);
int ungetch(int);
int getint(int*);
int fixgetint(int*);
float getfloat(int*);

int getint(int *pn){
    int c, sign;
    while(isspace(c = getch())) ; //skip white space
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-') c = getch();
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c != EOF) ungetch(c);

    return c;
}

/**
 * Exercise 5-1
 * As written getint treats a + or - not followed by a digit as a valid representation
 * of zero. Fix it to push such a character back on the input.
 */

int fixgetint(int *pn){
    int c, sign;
    while(isspace(c = getch())) ; //skips whitespace
    if(!isdigit(c) && c != EOF & c != '=' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-'){
        c = getch(); //reads the next char from the stream
        if(!isdigit(c)) ungetch(c); //pushes it back on the stream if it is not a digit
    }
    for(*pn = 0; isdigit(c); c = getch()) *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if(c != EOF) ungetch(c);
    return c;
}

/**
 * Exercise 5-2
 * Write getfloat, the floating point analog of getint.
 * What type does getfloat return as its function value?
 */

float getfloat(int *pn){

}