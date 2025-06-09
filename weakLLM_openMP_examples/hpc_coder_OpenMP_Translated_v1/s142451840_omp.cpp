#include<stdio.h>
#include<omp.h>
int main(){
	int x=0,y=0,i,j;
	#pragma omp parallel for private(x,y) shared(i,j)
	for(i=0; i<9; i++){
	y=0;
	++x;
	#pragma omp parallel for private(y) shared(j)
	for(j=0; j<9; j++){
	++y;
	printf("%dx%d=%d\n",x,y,x*y);
	};
	};
}