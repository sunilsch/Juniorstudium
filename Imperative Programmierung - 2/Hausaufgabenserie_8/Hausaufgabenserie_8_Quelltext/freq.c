#include <stdio.h>

// txt from https://gist.github.com/StevenClontz/4445774 : mobydick.txt

int main(){
    int c, i = 0;
    double nchar = 0.0, freq[26];

    /*Calculate frequencies*/
    while((c = getchar()) != EOF){
        if (c >= 'a' && c <= 'z'){
            ++freq[c - 'a'];
            ++nchar;
        } else if(c >= 'A' && c <= 'Z'){
            ++freq[c - 'A'];
            ++nchar;
        }
    }

    /* convert to percentages */
    for (nchar /= 100.0, i = 0; i < 26; ++i)
        freq[i] /= nchar;

    /* Prinout results*/
    for(int i = 0; i < 26; i++) printf("%c : %f\n", i+'a', freq[i]);
    return 0;
}