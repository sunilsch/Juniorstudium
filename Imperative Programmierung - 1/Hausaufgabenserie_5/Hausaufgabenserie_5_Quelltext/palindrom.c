#include <stdio.h>
#include <stdbool.h>
bool isPalindrom(int l, int i){
    int c = getchar();
    int r = true;
    if(i < l/2 || (l%2 == 1 && i <= l/2)) r = isPalindrom(l, i+1);
    else if(l%2 == 1) return true;
    return r ? getchar() == c : false;
}
void goback(int x){
    rewind(stdin);
    int i = 0;
    while(i < x) if(getchar() == '\n') i++;
}
int main(){
    int c;
    for(int g = 0; c != EOF; g++){
        int l;
        for(l = 0; (c = getchar()) != '\n' && c != EOF; l++);
        goback(g);
        if(isPalindrom(l,1)){
            printf("FOUND PALINDROM: ");
            goback(g);
            for(int j = 0; j < l+1; j++) printf("%c", getchar());
        }
    }
    return 0;
}