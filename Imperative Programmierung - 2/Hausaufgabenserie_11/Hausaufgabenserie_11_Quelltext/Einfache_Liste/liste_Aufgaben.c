#include <stdio.h>
#include "liste.h"


void readFromFile(list *liste){
    char data[20];
    scanf("%[a-z,A-Z, ]s", data);
    appendString(data, liste);
    if(getchar() == '\n') readFromFile(liste);
}

void task1and2(){
    // Task 1
    printf("---- Start task 1 ----\n");
    list * liste = newList(String); // String List
    printf("-> Read from file\n");
    readFromFile(liste); // read data from file to list
    printList(liste, NULL); // printout list
    printf("---- End of task 1 ----\n\n");

    // Task 2
    printf("---- Start task 2 ----\n");
    printf("-> Reverse list from 1\n");
    reverse(liste); // reverse list
    printList(liste, NULL); // print list
    printf("---- End of task 2 ----\n\n");
}

void task3(){
    //Task 3
    printf("---- Start task 3 ----\n");
    const enum types type = String; // String List

    printf("-> Create first list\n");
    list * liste1 = newList(type); // create first list
    appendString("habe", liste1);
    appendString("ich", liste1);
    appendString("so", liste1);
    printList(liste1, NULL);

    printf("-> Create second list\n");
    list * liste2 = newList(type); // create second list
    appendString("aber", liste2);
    appendString("es", liste2);
    appendString("schweigt", liste2);
    printList(liste2, NULL);

    printf("-> Merge lists\n");
    list * liste3 = merge(liste1, liste2, NULL); // create merged list
    printList(liste3, NULL);
    printf("---- End of task 3 ----\n\n");
}
void task4(){
    const enum types type = Int; // int List
    list * liste = newList(type);
    appendInt(1, liste);
    appendInt(2, liste);
    appendInt(5, liste);
    appendInt(6, liste);
    appendInt(3, liste);
    appendInt(4, liste);
    appendInt(5, liste);
    printList(liste, NULL);
    printf("\n");

    list * dest1 = newList(type);
    list * dest2 = newList(type);
    split(liste, dest1, dest2);

    printList(dest1, NULL);
    printList(dest2, NULL);

}

int main(){
    task1and2();
    task3();
    task4();
    return 0;
}