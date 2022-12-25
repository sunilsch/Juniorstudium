#include <stdio.h>
#include <stdbool.h>
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
        int pal[l/2];
        for(int i = 0;i < l/2;i++) pal[i] = getchar();
        if(l%2==1) c = getchar();
        bool palin = true;
        for(int j = l/2-1; j >= 0; j--) if(pal[j] != getchar()) palin = false;
        if(palin){
            printf("FOUND PALINDROM: ");
            for(int i = 0; i < l/2; i++) printf("%c", pal[i]);
            if(l%2==1) printf("%c", c);
            for(int i = l/2-1; i >= 0; i--) printf("%c", pal[i]);
            printf("\n");
        }
        c = getchar();
    }
    return 0;
}