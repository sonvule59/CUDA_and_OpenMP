#include <stdio.h>
#include <omp.h>

int main(){
	int i,k,j;
	#pragma omp parallel for private(i,k,j)
	for(i=1;i<10;i++){
		for(k=1;k<10;k++){
			j=i*k;
		printf("%dx%d=%d\n",i,k,j);
		}
	}
}