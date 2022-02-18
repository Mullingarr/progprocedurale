//
// Created by Mattia Lunardi on 11/02/22.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int palindroma,i,n;

    printf("Inserire la stringa: ");
    scanf("%s",str);

    n = strlen(str);

    palindroma = 1;
    for (i=0; i<n/2; i++)
        if (str[i] != str[n-1-i])
            palindroma = 0;

    if (palindroma==1)
        printf("La stringa %s e' palindroma\n",str);
    else
        printf("La stringa %s non e' palindroma\n",str);
    return 0;
}