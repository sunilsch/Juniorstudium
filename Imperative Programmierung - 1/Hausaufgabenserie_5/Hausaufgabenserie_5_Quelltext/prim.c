#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 1299827
int main(){
    bool sieb[MAX-2];
    for(int i = 0; i <= MAX-2; i++) sieb[i] = false;
    for(int i = 2; i < sqrt(MAX); i++)
        if(!sieb[i-2]){
            printf("%d\n", i);
            for(int j = i*i; j <= MAX; j+=i) sieb[j-2] = true;
        }
    for(int i = sqrt(MAX)+1; i <= MAX; i++) !sieb[i-2] ? printf("%d\n", i) : 0;
    return 0;
}