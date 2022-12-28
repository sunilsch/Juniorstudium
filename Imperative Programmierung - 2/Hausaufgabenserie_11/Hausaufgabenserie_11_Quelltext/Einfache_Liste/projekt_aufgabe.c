#include <stdio.h>
#include "liste.h"

int main(){
    list * liste = newList(Int);
    appendInt(10, liste);
    appendInt(20, liste);
    appendInt(30, liste);
    printList(liste,NULL);
    insertInt(100, liste, 1);
    printList(liste,NULL);
    removeAtIndex(liste, 2);
    printList(liste,NULL);
    swapAtIndex(liste, 1, 2);
    printList(liste,NULL);
}