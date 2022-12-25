#include "liste_lib.h"
#include <stdio.h>

int main(){
    list * liste = newList(Int);
    insertInt(1, liste);
    appendInt(2, liste); // this overwrites
    printList(liste, NULL);
    return 0;
}