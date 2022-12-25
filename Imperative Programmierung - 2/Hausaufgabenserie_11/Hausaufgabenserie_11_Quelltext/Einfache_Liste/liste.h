#ifndef _liste_h
#define _liste_h

#include <stdio.h>
#include <stdbool.h>

enum types {String, Int, Bool, Double, Long, Other};

typedef struct _listNode{
    void * data;
    struct _listNode * next;
}listNode;

typedef struct{
    struct _listNode * first;
    struct _listNode * last;
    struct _listNode * current;
    int len;
    enum types type;
}list;

/*_____Basic Functions_____*/
list * newList(enum types type);

void toFirst(list * liste);
void toLast(list * liste);
void next(list * liste);
listNode * getPrevious(list * liste, listNode * node);
void removeAtIndex(list * liste, int index);
listNode * nodeAtIndex(list * liste, int index);
void swapAtIndex(list * liste, int index1, int index2);
void toIndexWithCurrent(list * liste, int index);

void insert(void * data, list *liste);
void insertInt(int data, list *liste, int index);
void insertString(char * data, list *liste, int index);
void insertBool(bool data, list *liste, int index);
void insertDouble(double data, list *liste, int index);
void insertLong(long data, list *liste, int index);

void append(void * data, list *liste);
void appendInt(int data, list *liste);
void appendString(char * data, list *liste);
void appendBool(bool data, list *liste);
void appendDouble(double data, list *liste);
void appendLong(long data, list *liste);

void * convertIntToVoidReference(int data);
void * convertBoolToVoidReference(bool data);
void * convertDoubleToVoidReference(double data);
void * convertLongToVoidReference(long data);

/*_____Advanced Functions_____*/
void reverse(list *liste);
list * merge(list * source1, list * source2, bool (*comp)(void * a, void * b));
list * _mergeList(list * source1, list * source2, bool (*comp)(void * a, void * b));
void split(list * source, list * dest1, list * dest2);
void sort(list * liste, bool (*comp)(void * a, void * b));

bool compare(void * a, void * b, int type);

/*_____Print List_____*/
void printList(list * liste, void (*printFunction)(list * liste, listNode * node));
void printNode(list * list, listNode *startNote);

#endif