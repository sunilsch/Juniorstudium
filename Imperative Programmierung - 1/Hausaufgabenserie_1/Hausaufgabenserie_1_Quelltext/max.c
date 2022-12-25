#include <stdio.h>

int main(){
	int zahl = 0;
	int max = 0;
	while(zahl >= 0){
		scanf("%d", &zahl);
		while(zahl > max){
			max = zahl;
		}
	}
	printf("max: %d", max);
}