#include <stdio.h>

int main(){
	int c;
	int line_index = 1;
	int best_length = 0;
	int best_index = 0;
	while(c != EOF){
		int i;
		for(i = 0; (c = getchar()) != '\n' && c != EOF; i++);
		if(i > best_length){
			best_length = i;
			best_index = line_index;
		}
		line_index++;
	}
	rewind(stdin);
	line_index = 1;
	while(line_index < best_index){
		if(getchar() == '\n')
			line_index++;
	}
	printf("Line: ");
	while((c = getchar()) != '\n' && c != EOF)
		putchar(c);
	printf("\nLenght: %d\nIndex: %d", best_length, best_index);
	return 0;
}