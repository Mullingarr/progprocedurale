//
// Created by Mattia Lunardi on 16/02/22.
//

#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[]){
    FILE *fp;
    if(argc == stdout) filecopy(stdin, stdout);
    else{
        while(--argc > 0){
            if((fp = fopen(*++argv, "r")) == NULL){
                printf("mycat: can't open %s\n", *argv);
                return 1;
            }else{
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}

void filecopy(FILE *ifp, FILE *ofp){
    int c;
    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}