#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "liste.h"

int main(){
    list * liste = newList(String);
    appendString("30", liste);
    appendString("100", liste);
    toFirst(liste);
    insertString("20", liste);
    appendString("101", liste);
    appendBool(true, liste);
    printList(liste,NULL);
    return 0;
}