#include <stdio.h>

/*
    create own type to temporary save a person
*/
typedef struct {
    char firstName[20];
    char secondName[20];
    long nr;
    int birthYear;
}person;

/*
    gets persons from file and outputs it reversed
*/
void reverse(){
    person person;
    scanf("%s %s %ld %d", &person.firstName, &person.secondName, &person.nr, &person.birthYear);
    if(getchar() == '\n')
        read();
    printf("%ld %s %s %d\n", person.nr, person.secondName, person.firstName, person.birthYear);
}

int main(){
    reverse();
    return 0;
}