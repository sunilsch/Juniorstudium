#include <stdio.h>
#include <stdbool.h>

/* List Types
 * 
 * type = 0 -> char[]
 * type = 1 -> int
 * type = 2 -> bool
 * 
 */

typedef struct _listNode{
    void *data;
    struct _listNode *next;
}listNode;

typedef struct{
    struct _listNode *first;
    struct _listNode *last;
    int len;
    int type;
}list;

void append(void * data, list *liste){
    int type = liste->type;
    if(type == 0) data = strdup(data);
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

void readFromFile(list *liste){
    char data[20];
    scanf("%[a-z,A-Z, ]s", data);
    append(data, liste);
    if(getchar() == '\n') readFromFile(liste);
}

list * newList(int type){
    list *liste = (list *)malloc(sizeof(list));
    liste->last = NULL;
    liste->first = NULL;
    liste->len = 0;
    liste->type = type;
    return liste;
}


void printList(list * liste){
    printNode(liste, liste->first);
    printf("\n");
}

void printNode(list * list, listNode *startNote){
    if(list->type == 0) printf("%s\n", startNote->data);
    else if(list->type == 1) printf("%d\n", startNote->data);
    else if(list->type == 2) printf("%s\n", startNote->data ? "true" : "false");
    if(startNote->next != NULL) printNode(list, startNote->next);
}
bool compare(void * a, void * b, int type){
    if(type == 0) return strcoll(a,b) < 0;
    if(type == 1) return a < b;
    if(type == 2) return !a;
}
list * merge(list * source1, list * source2){ // lists must be sorted
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
            if(compare(current1->data, current2->data, type)){  
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
void sort(list * liste){
    int type = liste->type;
    int len = liste->len;
    listNode * current = NULL;
    for(int i = 0; i < len; i++){
        current = liste->first;
        for(int j = 0; j < len-1; j++){
            if(!compare(current->data, current->next->data, type)){
                void * tmp = current->next->data;
                current->next->data = current->data;
                current->data = tmp;
            }
            current = current->next;
        }
    }




}
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

void task1(){
    list * liste = newList(0); // String List
    readFromFile(liste);
    printList(liste);
}
void task2(){
    list * liste = newList(0); // String List
    readFromFile(liste);
    reverse(liste);
    printList(liste);
}
void task3(){
    int type = 0; // String List
    list * liste1 = newList(type);
    append("habe", liste1);
    append("ich", liste1);
    append("so", liste1);

    printList(liste1);
    printf("\n");

    list * liste2 = newList(type);
    append("aber", liste2);
    append("es", liste2);
    append("schweigt", liste2);

    printList(liste2);

    list * liste3 = merge(liste1, liste2);
    printList(liste3);
}
void task4(){
    const int type = 1; // int List
    list * liste = newList(type);
    append(1, liste);
    append(2, liste);
    append(5, liste);
    append(6, liste);
    append(3, liste);
    append(4, liste);
    append(5, liste);
    printList(liste);
    printf("\n");

    list * dest1 = newList(type);
    list * dest2 = newList(type);
    split(liste, dest1, dest2);

    printList(dest1);
    printf("\n");
    printList(dest2);

}
int main(){
    //task4();
    list * liste1 = newList(1);
    append(1232, liste1);
    append(234, liste1);
    append(324, liste1);
    sort(liste1);
    printList(liste1);

    list * liste2 = newList(1);
    append(100, liste2);
    append(4375, liste2);
    append(234, liste2);
    sort(liste2);
    printList(liste2);
    
    list * liste = merge(liste1, liste2);
    printList(liste);
    return 0;
}