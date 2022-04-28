//
// Created by Mattia Lunardi on 25/04/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NUMVOCALI 5
void riduci_iter(char *);
int vocale(char);
void riduci_sol_it(char *);
void riduci_ric(char *);
char *riduci_ric_no_modifica(const char *);
char vocali[5] = {'a', 'e', 'i', 'o', 'u'};

int main(){
    char s[7] = "abcdef";
    printf("prima della riduzione: %s\n", s);
    //riduci_iter(s);
    //riduci_sol_it(s);
    //riduci_ric(s);
    char *ris = riduci_ric_no_modifica(s);
    printf("dopo la riduzione s: %s\n", s);
    printf("dopo la riduzione ris: %s\n", ris);


}

/**
 * Versione con un while, for e un if
 * poco efficiente -- spiega
 */
void riduci_iter(char *s){
   char car_letto = s[0];
   char *ris = (char *) malloc(sizeof(s));
   int i = 0;
   int k = 0; //indice scrittura su k
   bool flag = true;
   while(car_letto != '\0'){
       printf("%c, %d\n", car_letto, i);
       for(int j = 0; j < NUMVOCALI; j++){
           if(car_letto == vocali[j]){
               printf("%c, %d == %c, %d\n", car_letto, i, vocali[j], j);
               flag = false;
           }
           //printf("%c, %d\n", vocali[j], j);
       }
       if(flag){
           ris[k] = car_letto;
           k++;
       }
       i++;
       car_letto = s[i];
       flag = true;
   }
   printf("dentro funzione riduci_iter, s: %s\n", s);
   printf("dentro funzione riduci_iter, ris: %s\n", ris);
   memcpy(s, ris, strlen(ris)+1);
}

/**
 * versione "ottima" del algoritmo sopra -- perché? -- spiega
 */
void riduci_sol_it(char *s){
    int i, j = 0;
    for(i = 0; s[i] != '\0'; i++) {
        if(vocale(s[i]) == 0) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

/**
 * Controlla sempre il primo carattere [0]
 * se questo è una vocale, trasla il resto della stringa
 * verso sinistra, sovra scrivendolo
 * @param s -> la stringa da ridurre
 */
void riduci_ric(char *s){
    if(strlen(s) == 0)
        return;
    riduci_ric(s+1); //richiamati sul carattere successivo

    if(vocale(s[0]) == 1) //se il carattere della posizione 0 è una vocale
        for(int i = 1; i < strlen(s)+1; i++)
            s[i-1] = s[i]; //ricopia la sotto-stringa
}

/**
 * Controlla sempre il primo carattere della stringa [0]
 * se questo è una vocale si richiama sul carattere successivo
 * altrimenti
 * crea una nuova stringa in cui ospitare il resto della stringa
 * richiamandosi finché non raggiunge la fine della stringa passata.
 * infine concatena la stringa "ospitante" con il resto ottenuto dalla
 * ricorsione e ritorna la stringa risultato
 * @param s ->  la stringa da ridurre, non viene modificata durante la modifica
 */
char *riduci_ric_no_modifica(const char *s){
    if(strlen(s) == 0) //caso base: ho raggiunto la fine della stringa (oppure ho passato una stringa non valida)
        return "";
    if(vocale(s[0]) == 1) //se carattere[0] è una vocale richiamati sul carattere successivo
        return riduci_ric_no_modifica(s+1);
    else{
        char *ris = (char *) malloc(sizeof(s)+1); //la stringa "ospitante", risultato
        char *suffisso = riduci_ric_no_modifica(s+1); // si richiama sul resto della stringa, ottenendo il "resto"
        ris[0] = s[0];
        ris[1] = '\0';
        strcat(ris, suffisso); //concateno le stringhe
        if(strlen(suffisso) > 0) //libero lo spazio
            free(suffisso);
        return ris; //ritorno la stringa risultato
    }
}

/**
 * ritorno
 * 1 se c è una vocale
 * 0 altrimenti
 */
int vocale(char c){
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}