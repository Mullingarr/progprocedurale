//
//  main.c
//  Somma arbitraria
//
//  Created by paolo massazza on 13/03/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>


/* Effettua la somma di un numero variabile di interi (i) o double (d) */

double Sum(const char * type,...)
{int i;
    double sum;
    va_list ap;
    va_start(ap,type);
    i=0; sum=0.0;
    while(type[i]!='\0')
    {if(type[i]=='i') sum+=va_arg(ap,int);
    else if(type[i]=='d') sum+=va_arg(ap,double);
    else break;
        i++;
    }
    va_end(ap);
    return sum;
}

int main (int argc, const char * argv[]) {
    int a;
    int b=100;
    printf("immetti un intero:");
    scanf("%d",&a);
    printf("\n");
    printf("%f\n",Sum("diiiiii",100.78,3,5,7,9,a,b));
    return 0;
}
