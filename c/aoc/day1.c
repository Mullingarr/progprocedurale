//
// Created by Mattia Lunardi on 03/03/22.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 1000

int *readlines(char *);
int *resize_array(int *, int);

int main(int argc, char **argv){

    char *filename = argv[1];
    printf("reading from %s\n", filename);
    int *nums = readlines(filename);
    printf("printing nums\n");
    for(int i = 0; i < 2000; i++){
        printf("%d\n", nums[i]);
    }

}

int *readlines(char *filename){
    int *nums = (int *) malloc(N * sizeof(int));
    int i = 0;
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        perror("Error while opening the file\n");
        return NULL;
    }
    else{
        char line[50];
        while(fgets(line, 50, fp) != NULL){
            if(i < N){ //still space in the array
                nums[i] = atoi(line);
                i++;
            }else{//create a new array witch has double the space
                fprintf(stderr, "resing the array\n");
                nums = resize_array(nums, i);
                i = 0; //reset counter
            }
        }
        fclose(fp);
    }
    return nums;
}

int *resize_array(int *arr, int i){
    int *new_arr = (int *) malloc((N + i + 1) * sizeof(int));//1000 + 999 + 1
    for(int j = 0; j < i; j++)
        new_arr[j] = arr[j];
    free(arr); //free the old array
    return new_arr;
}