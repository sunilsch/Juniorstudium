#include <stdio.h>
void nextChar(int c){
    if(c != '\n' && c != EOF){
        nextChar(getchar());
        putchar(c);
    }
}
int main(){
    int c;
    while((c = getchar()) != EOF){
        nextChar(c);
        putchar('\n');
    }
    return 0;
}