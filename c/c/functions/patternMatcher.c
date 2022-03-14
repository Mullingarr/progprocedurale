//
// Created by Mattia Lunardi on 09/02/22.
//

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int lim);
int strindex(char s[], char searchfor[]);
int strrindex(char s[], char t);

char pattern[] = "ould";

int main(){
    char line[MAXLINE] = "Ah Love! could you and I with Fate conspire\0\n";
    int found = 0;

    while(getLine(line, MAXLINE) > 0){
        if(strindex(line, pattern) >= 0){
            printf("%s\n", line);
            found++;
        }
    }
    printf("Found %d\n", found);
}

/* get line into s, return length */
int getLine(char line[], int lim){
    int c, i;
    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if(c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

/*return index of t in s, -1 if none*/
int strindex(char s[], char t[]){
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/**
 * return the position of the rightmost occurrence of t in s, or -1 if there is none
 */
int strrindex(char s [], char t){
    return -1;
}



