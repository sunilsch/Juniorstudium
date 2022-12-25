#include <stdio.h>

int main () {
	int c, nl, nc;
	nl = 0;
	nc = 0;
	while((c = getchar()) != EOF){
		if(c == '\n'){
			++nl;
			nc = 0;
		} else {
			++nc;
		}
	}
	if(nc != 0){
		++nl;
		printf("Letzte Zeile unvollstaending mit %d Zeichen\n", nc);
	}
	printf("Insgesamt %d Zeilen\n",nl);
}