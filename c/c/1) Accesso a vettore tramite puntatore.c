//
//  main.c
//  puntatori
//
//  Created by admin on 03/03/21.
//  Copyright © 2021 admin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    long double a [20];
    long double *pt=a;
    a[0]=2.1;
    for (int i=1; i<20; i++) a[i]=a[i-1]*2.1;
    for (int i=0; i<20; i++) {
        printf("indirizzo di a[%d]:%p\n",i,pt+i);
        printf("valore di a[%d]:%Lf\n",i,*(pt+i));
        
        //%Lf indica la stampa di un long double (%f float, %lf double)
    }
    return 0;
}
