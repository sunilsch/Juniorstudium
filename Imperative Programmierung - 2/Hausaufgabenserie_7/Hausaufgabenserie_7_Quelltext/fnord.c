#include<stdio.h>


double fnord1(double v) {
    int c = getchar();
    if(c >= '0' && c <= '9') return fnord1(v *10+(c-'0'));
    ungetc(c, stdin);
    return v;
}

double fnord2(){
    double v = 0.0;
    int c = getchar();
    while(c >= '0' && c <= '9'){
        v = v * 10 + (c-'0');
        c = getchar();
    }
    ungetc (c, stdin );
    return v;
}

int main(){
    printf("Zahl: ");
    printf("%f", fnord2());
    return 0;
}