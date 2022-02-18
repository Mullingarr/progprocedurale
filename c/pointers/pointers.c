//
// Created by Mattia Lunardi on 11/02/22.
//

#include <stdio.h>

int main(){

    int a = 24;
    int b = 10;
    int *p_toA = &a;

    printf("a: %d\n", a);
    printf("&a : %d\n", &a);
    printf("pToA: %d\n", p_toA);
    printf("*pToA: %d\n", *p_toA); //*p_toA - value at the address pointed by p
    printf("&ptoA: %d\n", &p_toA);

    *p_toA = 12; //the value pointed to -> dereferencing
    printf("*pToA: %d\n", *p_toA);
    *p_toA = *p_toA + *(&b);
    printf("*pToA: %d\n", *p_toA);

    //pointer arithmetic
    printf("size of int: %d bytes\n", sizeof(int)); //bytes
    printf("ptoA: %d\n", p_toA);
    printf("ptoA =+ 1: %d\n", p_toA += 1);

    return 0;
}