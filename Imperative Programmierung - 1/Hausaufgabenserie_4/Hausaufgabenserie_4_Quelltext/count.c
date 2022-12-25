#include <stdio.h>

#define OUT 0
#define WORD 1
#define NUMBER 2
#define MIXED 3 

#define true 1
#define false 0

int nwords, nnumbers, nmixed, state;

void erhoehe(){
	if(state == WORD) nwords++;
	if(state == NUMBER) nnumbers++;
	if(state == MIXED) nmixed++;
}

int main(){
	int nchars, nout, newline, c;
	nchars = nwords = nnumbers = nmixed = nout = 0;
	state = OUT;
	for(; (c = getchar()) != EOF; nchars++){
		newline = false;
		if(isalpha(c)){
			if(state == OUT || state == WORD){
				state = WORD;
			} else{
				state = MIXED;
			}
		} else if(isdigit(c)){
			if(state == OUT || state == NUMBER){
				state = NUMBER;
			} else{
				state = MIXED;
			}
		} else {
			nout++;
			erhoehe(state);
			if(c == '\n') newline = true;
			state = OUT;
		}
	}
	if(newline == false) erhoehe();
	printf("%d Zeichen\n%d Worte\n%d Zahlen\n%d gemischte Sequenzen\n%d sontige Zeichen\n", nchars, nwords, nnumbers, nmixed, nout);
	if(newline == false) printf("Letze Zeichenfolge unvollständig.");
}