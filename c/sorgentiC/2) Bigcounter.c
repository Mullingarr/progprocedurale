//
//  main.c
//  BigCounter
//
//  Created by paolo massazza on 14/02/22.
//

#include <stdio.h>
#define DIM 10;

#define INC(v,n) { unsigned carry=0; int i=0;\
do{ unsigned a=v[i];\
v[i]= (v[i] +1)%DIM;\
if (v[i]<=a) {carry=1;i++;}\
else carry=0;\
} while (carry!=0&&i<n);}

void Inc(unsigned v[],int n){
    unsigned carry=0; int i=0;
    do { unsigned a=v[i];
        v[i]= (v[i] +1)%DIM;
        if (v[i]<=a) {carry=1;i++;}
        else carry=0;
    } while (carry!=0&&i<n);
}

void printBig(unsigned v[],int n){
    printf("->");
    for (int i=n-1; i>=0; i--) {
        printf("%u",v[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    unsigned big[3];
    big[0]= big[1]=big[2]=0;
    int j;
    for (j=1; j<150; j++) INC(big,3);
        //Inc(&big[0],2);

    //printf("big[0]=%u\n",big[0]);
    
   // printf("big[1]=%u\n",big[1]);
    
   // printf("%u%u\n",big[1],big[0]);
    
    printBig(big,3);
    printf("%lu",sizeof(unsigned));
    return 0;
}
