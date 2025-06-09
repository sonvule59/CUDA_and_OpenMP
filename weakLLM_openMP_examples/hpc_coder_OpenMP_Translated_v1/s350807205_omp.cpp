#include<stdio.h>
#include<omp.h>

int main(){
	int i;
	int j;
	int h;
	#pragma omp parallel for private(i,j,h)
	for(i = 1; i<=9;i++){
		for(j =1; j<=9;j++){
			h = i * j;
			printf("%dx%d=%d\n",i,j,h);
		}
	}

}