#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	for(int i = 0; i <= 10; i++){
		double random = ((double) rand()) / ((double)RAND_MAX);
		printf("%lf\n", random);
	}
}