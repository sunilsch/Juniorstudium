


/*************************************************************
 * @file liste.c
 * @author Linus Schumann
 * @brief List-Helper file, when working with simply concatenated lists
 * @version 0.2
 * @date 2022-12-23
 * @copyright Copyright (c) 2022
 * 
 * <---------------------->
 * @warning When using append(void * data, list *liste) or insert(void * data, list * liste):
 *          - data must be saved before appending or inserting using malloc
 *           -> because only a reference is saved
 *          With append[Datatype](Datatype data, list *liste)
 *          - data is saved with malloc in function, the user don't have to do it
 * <----------------------->
 * 
 **************************************************************/


/*************______Simply Concatenated List______*************/

#include "liste.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**************************************************************/
/********************___Basic Functions___*********************/
/**************************************************************/

/**************___Function to create new list___***************/

list * newList(enum types type){
    list *liste = (list *)malloc(sizeof(list));
    liste->last = NULL;
    liste->current = NULL;
    liste->first = NULL;
    liste->len = 0;
    liste->type = type;
    return liste;
}

/*********************___Move current ___**********************/

void toFirst(list * liste){
    liste->current = liste->first;
}

void toLast(list * liste){
    liste->current = liste->last;
}

void next(list * liste){
    if(liste->current->next != NULL){
        liste->current = liste->current->next;
    }
}

void toIndexWithCurrent(list * liste, int index){
    toFirst(liste);
    for(int i = 0; i < index; i++){
        next(liste);
    }
}


/********___Function to get prev element of list___************/

listNode * getPrevious(list * liste, listNode * node){
    listNode * currentSave = liste->current;
    toFirst(liste);
    if(liste->first != node){
        while(liste->current->next != node){
            next(liste);
        }
    } else {
        printf("You tried to get Previous element of first element!!, This can cause problems");
        exit(1);
    }
    listNode * r = liste->current;
    liste->current = currentSave;
    return r;
}


/**************___Remove element at an Index___****************/

void removeAtIndex(list * liste, int index){
    listNode * currentSave = liste->current;
    toFirst(liste);
    for(int i = 0; i < index; i++){
        next(liste);
    }
    if(liste->current == liste->first){
        liste->first = liste->first->next;
    } else {
        listNode * prev = getPrevious(liste, liste->current);
        prev->next = liste->current->next;
    }

    liste->current = currentSave;
    liste->len -= 1;
}


/********************__Get node at index___********************/

listNode * nodeAtIndex(list * liste, int index){
    listNode * outputNode = liste->first;
    for(int i = 0; i < index; i++){
        outputNode = outputNode->next;
        if(outputNode == NULL){
            printf("INDEX OUT OF RANGE!");
            exit(1);
        }
    }
    return outputNode;
}


/*************__Swap data from index 1 and 2___****************/

void swapAtIndex(list * liste, int index1, int index2){
    listNode * first = nodeAtIndex(liste, index1);
    listNode * second = nodeAtIndex(liste, index2);
    // swap data
    void * dataSave = first->data;
    first->data = second->data;
    second->data = dataSave;
}

void insert(void * data, list * liste){
    if(liste->current == liste->last){
        append(data, liste);
    } else {
        liste->len += 1;
        listNode *new = (listNode *)malloc(sizeof(listNode));
        new->data = data;

        new->next = liste->current;
        if(liste->first != liste->current){
            getPrevious(liste, liste->current)->next = new;
        } else {
            liste->first = new;
        }
    }
}


/********************insert() Functions___******************/

void insertInt(int data, list * liste, int index){
    if(liste->type == 1){
        if(index >= 0){
            toIndexWithCurrent(liste, index);
        }
        
        insert(convertIntToVoidReference(data), liste);
    } else {
        printf("List isn't from type int\n");
    }
}

void insertString(char * data, list *liste, int index){
    if(liste->type == 0) insert((void *)strdup(data), liste);
    else printf("List isn't from type string\n");
}

void insertBool(bool data, list *liste, int index){
    if(liste->type == 2){
        insert(convertBoolToVoidReference(data), liste);
    } else {
        printf("List isn't from type bool\n");
    }
}

void insertDouble(double data, list *liste, int index){
    if(liste->type == 3){
        insert(convertDoubleToVoidReference(data), liste);
    } else {
        printf("List isn't from type double\n");
    }
}

void insertLong(long data, list *liste, int index){
    if(liste->type == 4){
        insert(convertLongToVoidReference(data), liste);
    } else {
        printf("List isn't from type long\n");
    }
}


/********************___append() Functions___******************/

void append(void * data, list *liste){
    listNode *new = (listNode *)malloc(sizeof(listNode));
    new->data = data;
    new->next = NULL;
    if(liste->last == NULL){
        liste->first = new;
    } else {
        liste->last->next = new;
    }
    liste->last = new;
    liste->len += 1;
}

void appendString(char * data, list *liste){
    if(liste->type == 0) append((void *)strdup(data), liste);
    else printf("List isn't from type string\n");
}

void appendInt(int data, list *liste){
    if(liste->type == 1){
        append(convertIntToVoidReference(data), liste);
    } else {
        printf("List isn't from type int\n");
    }
}

void appendBool(bool data, list *liste){
    if(liste->type == 2){
        append(convertBoolToVoidReference(data), liste);
    } else {
        printf("List isn't from type bool\n");
    }
}

void appendDouble(double data, list *liste){
    if(liste->type == 3){
        append(convertDoubleToVoidReference(data), liste);
    } else {
        printf("List isn't from type double\n");
    }
}

void appendLong(long data, list *liste){
    if(liste->type == 4){
        append(convertLongToVoidReference(data), liste);
    } else {
        printf("List isn't from type long\n");
    }
}

void * convertIntToVoidReference(int data){
    long * value = (long *)malloc(sizeof(long));
    *value = data;
    return (void *)value;
}

void * convertBoolToVoidReference(bool data){
    bool * value = (bool *)malloc(sizeof(bool));
    *value = data;
    return (void *)value;
}

void * convertDoubleToVoidReference(double data){
    double * value = (double *)malloc(sizeof(double));
    *value = data;
    return (void *)value;
}

void * convertLongToVoidReference(long data){
    long * value = (long *)malloc(sizeof(long));
    *value = data;
    return (void *)value;
}


/*****************___Functions to print list******************/

void printList(list * liste, void (*printFunction)(list * liste, listNode * node)){
    if(liste->type == Other){
        if(printFunction == NULL) return;
    } else {
        if(printFunction == NULL) printFunction = printNode;
    }
    printf("---- List: ----\n");
    listNode * current = liste->first;
    while(current != NULL){
        printFunction(liste, current);
        current = current->next;
    }
    printf("---------------\n");
}

void printNode(list * liste, listNode *node){
    printf("  -> ");
    if(liste->type == 0) printf("%s\n", node->data);
    else if(liste->type == 1) printf("%d\n", *(int *)node->data);
    else if(liste->type == 2) printf("%s\n", *(bool *)node->data ? "true" : "false");
    else if(liste->type == 3) printf("%f\n", *(double *)node->data);
    else if(liste->type == 4) printf("%ld\n", *(long *)node->data);
}



/**************************************************************/
/********************___Advanced Functions___******************/
/**************************************************************/

/********************___reverse() Functions___*****************/

void reverse(list *liste){
    listNode * prev = NULL;
    listNode * current = liste->first;
    listNode * next;
    liste->last = liste->first;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    liste->first = prev;
}

/*****___Predefined Compare functions for sort and merge___****/

bool compareString(void * a, void * b){
    return strcoll(a,b) < 0;
}

bool compareInt(void * a, void * b){
    return *(int *)a < *(int *)b;
}

bool compareBool(void * a, void * b){
    return !*(bool *)a;
}

bool compareDouble(void * a, void * b){
    return *(double *)a < *(double *)b;
}

bool compareLong(void * a, void * b){
    return *(long *)a < *(long *)b;
}

/************___Function for merging two lists___**************/

list * _mergeList(list * source1, list * source2, bool (*comp)(void * a, void * b)){
    if(source1->type != source2->type){
        printf("Source lists must consists of the same data type");
        return NULL;
    }
    int type = source1->type;
    list * dest = newList(type);
    dest->len = source1->len + source2->len;
    listNode * current1 = source1->first;
    listNode * current2 = source2->first;
    while(current1 != NULL || current2 != NULL){
        if(current1 == NULL){
            append(current2->data, dest);
            current2 = current2->next;
        } else if(current2 == NULL){
            append(current1->data, dest);
            current1 = current1->next;
        } else {
            if(comp(current1->data, current2->data)){  
                append(current1->data, dest);
                current1 = current1->next;  
            } else {
                append(current2->data, dest);
                current2 = current2->next;
            }
        }
    }
    return dest;
}

list * merge(list * source1, list * source2, bool (*comp)(void * a, void * b)){
    if(comp == NULL){
        int type = source1->type;
        if(type == 0) return _mergeList(source1, source2, compareString);
        if(type == 1) return _mergeList(source1, source2, compareInt);
        if(type == 2) return _mergeList(source1, source2, compareBool);
        if(type == 3) return _mergeList(source1, source2, compareDouble);
        if(type == 4) return _mergeList(source1, source2, compareLong);
    } else {
        return _mergeList(source1, source2, comp);
    }
    return NULL;
}

/****************___Functions for sorting list*****************/

void bubbleSort(list * liste, bool (*comp)(void * a, void * b)){
    int len = liste->len;
    listNode * current = NULL;
    for(int i = 0; i < len; i++){
        current = liste->first;
        for(int j = 0; j < len-1; j++){
            if(!comp(current->data, current->next->data)){
                void * tmp = current->next->data;
                current->next->data = current->data;
                current->data = tmp;
            }
            current = current->next;
        }
    }
}

void sort(list * liste, bool (*comp)(void * a, void * b)){
    if(comp == NULL){
        int type = liste->type;
        if(type == 0) bubbleSort(liste, compareString);
        if(type == 1) bubbleSort(liste, compareInt);
        if(type == 2) bubbleSort(liste, compareBool);
        if(type == 3) bubbleSort(liste, compareDouble);
        if(type == 4) bubbleSort(liste, compareLong);
    } else {
        bubbleSort(liste, comp);
    }
}

/*****************___Function to split list___*****************/

void split(list * source, list * dest1, list * dest2){
    int splitLen = source->len/2;
    listNode * current = source->first;
    for(int i = 0; i < splitLen; i++){
        append(current->data, dest1);
        current = current->next;
    }
    for(int i = splitLen; i < source->len; i++){
        append(current->data, dest2);
        current = current->next;
    }
}