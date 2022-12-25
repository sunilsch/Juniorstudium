#include <stdio.h>

void reversed_order(){
    int n;
    scanf("%d", &n);
	printf("binary number in reversed order: ");
    while(n > 0){
        printf("%d", n % 2);
        n /= 2;
    }
}

void right_order(){
    int n, r, b = 0, i = 1;
    scanf("%d", &n);
    while(n > 0){
        r = n % 2;
        n /= 2;
        b += r*i;
        i *= 10;
    }
    printf("binary number in right order: %d", b);
}

int main() {
    reversed_order();
    return 0;
}