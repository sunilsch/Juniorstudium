#include <stdio.h>
int main(){
	int row = 1;
	int column = 1;
	int c;
	printf("%d.%d ", column, row);
	while((c = getchar()) != EOF){
		if(c == ' ') {
			row++;
			printf("\n%d.%d ", column, row);
		} else if(c == '\n') {
			row = 1;
			column++;
			printf("\n%d.%d ", column, row);
		} else {
			putchar(c);
		}
		
		
	}
	return 0;
}