#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// txt from https://gist.github.com/StevenClontz/4445774 : mobydick.txt

const char alphabet[29] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', ' ', ',', '.'};

// calculate frequencies for random text
void calculateFreq(double freq[29][29][29]){
    int c;
    double nChars[29][29];
    memset(nChars, 0.0, sizeof nChars);
    int a = -1, b = -1;

    // Calculate frequencies
    while((c = getchar()) != EOF){
        bool x = (a >= 0 && b >= 0);
        if (c >= 'a' && c <= 'z') c = c - 'a';
        else if(c >= 'A' && c <= 'Z') c = c - 'A';
        else if(c == ' ') c = 26;
        else if(c == ',') c = 27;
        else if(c == '.') c = 28;
        else continue;
        if(x){
            ++freq[a][b][c];
            ++nChars[a][b];
        }
        a = b;
        b = c;
    }

    // convert to percentages
    for(int i = 0; i < 29; i++){
        for(int j = 0; j < 29; j++){
            nChars[i][j] /= 100.0;
            for (int k = 0; k < 29; k++)
                freq[i][j][k] /= nChars[i][j];
        }
    }
}

// get random double between fMin and fMax
double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

// generate random text with calculated frequencies
void makeText(double freq[29][29][29], int n){
    srand(time(NULL));
    int a = 28, b = 26, x; // 28 = point, 26 = space
    for(int i = 0; i < n; i++){
        double rand = fRand(0.0, 100.0); // get random double
        double sum = 0.0;
        for(int c = 0; c < 29; c++){ // get random char
            sum += freq[a][b][c];
            if(sum >= rand){
                printf("%c", alphabet[c]);
                x = c;
                break;
            }
        }
        a = b;
        b = x;
    }
}

int main(){
    double freq[29][29][29];
    memset(freq, 0.0, sizeof freq);
    calculateFreq(freq);
    makeText(freq, 200);
}