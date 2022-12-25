#include <stdio.h>
#include <stdbool.h>

int main(){
	int max = 0;
	int lines = 1;
	int c;
	{
		int new_max = 0;
		while((c = getchar()) != EOF){
			if(c == '\n'){
				new_max = 0;
				lines+=1;
			} else {
				new_max += 1;
			}
			if(new_max > max){
				max = new_max;
			}
		}
	}
	for(int i = 0; i < max; i++){ // für jede Spalte
		rewind(stdin);
		for(int l = 0; l < lines; l++){ // für jede Zeile
			bool point = true;
			int new_c;
			for(int j = 0; (c = getchar()) != '\n' && c != EOF; j++){
				if(i == j){
					point = false;
					new_c = c;
				}
			}
			putchar(point ? '.' : new_c);
		}
		putchar('\n');
	}
	return 0;
}