#include <stdio.h>
#include <stdbool.h>
int main () {
    int zahl = 0;
	bool first = true;
	int change = 0;
    while (zahl < 2) {
        printf("Zahl: ");
        scanf("%i",&zahl);
    }
    printf("Primfaktorzerlegung: ");
    int i = 2;
    while (i <= zahl) {
        while (zahl%i != 0) {
            i++;
        }
        while (zahl%i == 0) {
            zahl /= i;
			change++;
        }
		if(change == 1){
			printf(first == true ? "%i" : "*%i",i);
			first = false;
		} else if(change > 1){
			printf(first == true ? "(%i^%d)" : "*(%i^%d)",i,change);
			first = false;
		}
		change = 0;
    }
    return 0;
}