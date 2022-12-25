#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000
#define N 26

char imsg[MAX]; /* plaintext */
char omsg[MAX]; /* ciphertext */

bool onlyLower = false;

double efreq[N] = {
    8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0,
    6.1, 7.0, 0.2, 0.8, 4.0, 2.4, 6.7,
    7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8,
    1.0, 2.4, 0.2, 2.0, 0.1
};

void cipher(int shift){
    int i, c;
    for (i = 0; imsg[i]; i++){
        c = imsg[i];
        omsg[i] = (c >= 'a' && c <= 'z') ? ((c - 'a') + shift) % N + 'a' : ((c >= 'A' && c <= 'Z') ? ((c - 'A') + shift) % N + (onlyLower ? 'a' : 'A') : c);
    }
    omsg[i] = '\0';
}

void computeOfreq(double *ofreq){
    int i;
    double nchar;
    for (nchar = 0.0, i = 0; imsg[i]; ++i){
        int c = imsg[i];
        if (c >= 'a' && c <= 'z'){
            ++ofreq[c - 'a'];
            ++nchar;
        } else if(c >= 'A' && c <= 'Z'){
            ++ofreq[c - 'A'];
            ++nchar;
        }
    }
    /* convert to percentages */
    for (nchar /= 100.0, i = 0; i < N; ++i)
        ofreq[i] /= nchar;
}
void computeSMIN(int *smin, double *ofreq){
    double chmin = HUGE_VAL; /* + oo , in math .h */
    double chisq;
    int i, shift;
    for (shift = 0; shift < N; ++shift){
        for (chisq = 0.0, i = 0; i < N; ++i)
            chisq += pow(ofreq[(i + shift) % N] - efreq[i], 2.0) / efreq[i];
        if (chisq < chmin){
            chmin = chisq;
            *smin = shift;
        }
    }
    printf(" Best shift : %d\n", *smin);
}
void decipher(){
    double ofreq[N];
    int smin;
    /* reset data */
    for (int i = 0; i < N; i++)
        ofreq[i] = 0;
    computeOfreq(ofreq);
    computeSMIN(&smin, ofreq);
    /* decode */
    cipher(N - smin);
}

int main(){
    int shf;
    printf(" Shift = ");
    scanf("%d", &shf);
    int ch;                                            // replacement for fpurge
    while( (ch = getchar() ) != EOF && ch != '\n' ){;} // replacement for fpurge
    printf(" Message = ");
    gets(imsg);
    //cipher(shf);
    cipher(shf);
    printf(" Coded = %s\n", omsg);
    strcpy(imsg, omsg);
    decipher();
    printf(" Decoded = %s\n", omsg);
    return 0;
}