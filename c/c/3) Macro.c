//
//  main.c
//  Macro
//
//  Created by admin on 17/03/21.
//  Copyright © 2021 admin. All rights reserved.
//

#include <stdio.h>

#define Min(x,y) ((x)<(y)?(x):(y))
#define Quadrato(x) ((x)*(x))

int main(int argc, const char * argv[]) {

    int a,b,c;
    a=10;b=20;
    c=Min(++a,b);
    
    //indovinate che valore viene stampato e trovate il motivo
    
    printf("quadrato di %d: %d\n",a,Quadrato(a));

    return 0;
}
