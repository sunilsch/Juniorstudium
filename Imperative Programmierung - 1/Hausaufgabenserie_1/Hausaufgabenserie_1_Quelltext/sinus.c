#include <stdio.h>
#include <math.h>

double bogen_mas(int grad){
	return ((double)grad/180) * M_PI;
}
double calculate_sinus(int grad){
	double bogenMas = bogen_mas(grad);
	double result = 0;
	for(int i = 0; i <= 50; i++){
		result += (pow(-1, i))*((pow(bogenMas, (2*i)+1))/(tgamma(((2*i)+1)+1)));
	}
	return result;
}
int main(){
	printf("  Grad      Sinus\n");
	for(int i = 0; i <= 720; i+=15){
		printf("%5d\370    %10f\n", i, calculate_sinus(i));
	}
	return 0;
}