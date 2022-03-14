//
// Created by Mattia Lunardi on 15/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#define NUMSIZE 10

struct tnode{
    int value;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, int *);
void treeprint(struct tnode *);
int getvalue(struct tnode *, int value);
struct tnode *talloc();
int *intdup(int *);
int compare(int x, int *y);


int main(){
    struct tnode *root;
    root = NULL;
    int nums[NUMSIZE];

    for(int i = 0; i < NUMSIZE; i++){
        nums[i] = i;
    }

    printf("creating the tree");
    for(int i = 0; i < NUMSIZE; i++){
        root = addtree(root, &nums[i]);
    }
    treeprint(root);
}

int getvalue(struct tnode *node, int value){
    if(node->value == value)
        return 0;
    else if(node->left->value < value) getvalue(node->left, value);
    else getvalue(node->right, value);
    return -1;
}

int compare(int x, int *y){
    if(x == *y)
        return 0;
    else if(x < *y)
        return -1;
    else
        return 1;
}

struct tnode *addtree(struct tnode *p, int *w){
    int cond;
    if(p == NULL){
        p = talloc();
        p->value  = *intdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = compare(*w,&p->value)) == 0)
        p->count++; //repeated value
    else if(cond < 0) //less than into left subtree
        p->left = addtree(p->left, w);
    else p->right = addtree(p->right, w); //greater than into right subtree
    return p;
}

/**
 * in-order print of tree p
 */
void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("value: %d, count: %d\n", p->value, p->count);
        treeprint(p->right);
    }
}

/**
 * Makes a duplicate of w
 */
int *intdup(int *w){
    int *p;
    p = (int *) malloc(sizeof(w));
    if(p != NULL)
        *p = *w;
    return p;
}

struct tnode *talloc(){
    return (struct tnode *) malloc(sizeof(struct tnode));
}
