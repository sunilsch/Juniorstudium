#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "liste.h"

typedef struct{
    int j;
    int n;
}t;

void printT(list * liste, listNode *node){
    int j = ((t*)(node->data))->j;
    int n = ((t*)(node->data))->n;
    printf("  -> %d und %d\n", j, n);
}

bool comp(void * a, void * b){
    if((int)(((t*)(a))->j) == (int)(((t*)(b))->j)){
        return (int)(((t*)(a))->n) < (int)(((t*)(b))->n);
    }
    return (int)(((t*)(a))->j) < (int)(((t*)(b))->j);
}

int main(){ //  Test with own list of struct
    list * liste = newList(Other);
    t * t1 = (t*)malloc(sizeof(t));
    t * t2 = (t*)malloc(sizeof(t));
    t * t3 = (t*)malloc(sizeof(t));
    t1->j = 10;
    t1->n = 220;
    t2->j = 15;
    t2->n = 60;
    t3->j = 10;
    t3->n = 120;
    append(t1, liste);
    append(t2, liste);
    append(t3, liste);
    sort(liste, comp);
    printList(liste, printT);
}