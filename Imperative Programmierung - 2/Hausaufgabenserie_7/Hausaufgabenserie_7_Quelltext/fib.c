#include <stdio.h>

long long fib1(long long i){
    if(i < 2) return i;
    return fib1(i - 1) + fib1(i - 2);
}

long long fib2(long long n){
    long long a = 1, b = 1;
    printf("%d :   %d\n", 1, 1);
    printf("%d :   %d\n", 2, 1);
    for(int i = 2; i < n; i++){
        long long c = a + b;
        printf("%d :   %lld\n", i+1, c);
        a = b;
        b = c;
    }
}


int main(){
    
   //for(int i = 0; i < 50; i++){
    //    printf("%d : %lld\n", (i+1), fib1(i));
    //}
    
    fib2(50);
    return 0;
}