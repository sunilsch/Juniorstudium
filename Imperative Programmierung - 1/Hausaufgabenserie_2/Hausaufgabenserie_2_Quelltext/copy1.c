#include <stdio.h>
#include <stdbool.h>
int main(){
	int c;
	bool lastspace = false;
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\t'){
			if(!lastspace){
				putchar(' ');
			}
			lastspace = true;
		} else {
			lastspace = false;
			putchar(c);
		}
		
	}
	return 0;
}