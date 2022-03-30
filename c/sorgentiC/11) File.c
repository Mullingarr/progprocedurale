//
//  main.c
//  File
//
//  Created by paolo massazza on 26/03/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void   togli_vocali(FILE *, FILE *);
void   prn_info(char *);

int main(int argc, char **argv)
{
    FILE   *ifp, *ofp;
    
    if (argc != 3) {
        prn_info(argv[0]);
        exit(1);
    }
    ifp = fopen(argv[1], "r");     /* open for reading */
    if (ifp==NULL)
    {printf("Attenzione: file di input non trovato");
        return 1;}
    ofp = fopen(argv[2], "w");     /* open for writing */
    togli_vocali(ifp, ofp);
    fclose(ifp);
    fclose(ofp);
    return 0;
}

void togli_vocali(FILE *ifp, FILE *ofp)
{
    int  c;
    while ((c = getc(ifp)) != EOF) {
        switch(c){
            case 'a': break;
            case 'e': break;
            case 'i': break;
            case 'o': break;
            case 'u': break;
            default :  putc(c, ofp);}
    }
}

void prn_info(char *pgm_name)
{
    printf("\n%s%s%s\n\n%s%s\n\n",
           "Uso:  ", pgm_name, "  file_di_input  file_di_output",
           "Il contenuto del file di testo file_di_input  viene trascritto nel",
           "file di testo file_di_output eliminando tutte le vocali (minuscole).");
}
