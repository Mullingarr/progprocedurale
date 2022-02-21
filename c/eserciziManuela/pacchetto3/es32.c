//
// Created by Mattia Lunardi on 11/02/22.
//

#include <stdio.h>

float radice (float x, float epsilon);
float val_ass(float x);
float leggi_positivo ();

int main() {
    float x,epsilon,ris;
    x = leggi_positivo();
    epsilon = leggi_positivo();
    ris =  radice (x, epsilon);
    printf("La radice di %.10f e' %.10f [%.10f^2 = %.10f]\n",x,ris,ris,ris*ris);
    return 0;
}

float leggi_positivo ()
{
    float x;
    do
    {
        printf("Inserire num positivo:");
        scanf("%f",&x);
        if (x<0)
            printf("num inserito negativo, riprova!\n");
    } while(x<0);

    return x;
}

float radice (float x, float epsilon)
{
    float y = (x+1)/2;
    while (val_ass(y*y - x)>epsilon)
        y = (y + x/y)/2;
    return y;
}

float val_ass(float x)
{
    if (x<0)
        return -x;
    else
        return x;
}