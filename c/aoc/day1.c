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
    int max = 1000;
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        perror("Error while opening the file\n");
        return NULL;
    }
    else{
        char line[50];
        while(fgets(line, 50, fp) != NULL){
            if(i == max){
                max+=1000;
                nums = resize_array(nums, max);
                //nums[i] = atoi(line);
            }
            else{
                nums[i] = atoi(line);
                i++;
            }
        }
        fclose(fp);
    }
    return nums;
}

int *resize_array(int *arr, int i){
    printf("Resizing the array %d\n", i);
    (int *) realloc(arr,i);
    return arr;
}