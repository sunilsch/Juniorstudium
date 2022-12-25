#include <stdio.h>
#include <stdbool.h>

void fak(int n){
    //init array and vars
    unsigned long long A[50000];
    for(int i = 0; i < 50000; i++) A[i] = 0;
    A[0] = 1;
    unsigned long long rest = 0;

    // calculate
    for(unsigned long long i = 1; i <= n; i++){
        for(int j = 0; j < 49999; j++){
            A[j]*=i;
            A[j] += rest;
            rest = A[j] / 10000000000;
            A[j] %= 10000000000;
        }
        if(rest != 0) return;
    }

    // print result
    bool notUsed = true;
    bool first = true;
    for(int i = 49999; i >= 0; i--){
        if(A[i] != 0) notUsed = false;
        if(notUsed) continue;
        if(first) printf("%llu", A[i]);
        else printf("%010llu", A[i]);
        first = false;
    }
}

int main(){
    int n;
    printf("Zahl: ");
    scanf("%d", &n);
    printf("Die Fakultaet von %d ist: ", n);
    fak(n);
    return 0;
}