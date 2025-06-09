#include<stdio.h>
#include<omp.h>
int main(void){
	int a, b, c;
	#pragma omp parallel for private(a, b, c)
	for(a=1;a<10;a++){
		for(b=1;b<10;b++){
		c = a * b;
		printf("%dx%d=%d\n", a, b, c);
		}
	}
	return 0;
}