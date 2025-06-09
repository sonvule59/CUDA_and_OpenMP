#include <stdio.h>
#include <omp.h>
int main(){
	#pragma omp parallel for
	for(int i=1; i<=9 ; i++ ){
		for(int b=1; b<=9 ; b++ ){
			printf("%dx%d=%d\n",i,b,i*b);
			
		}
		
	}
	
	return 0;
	
}