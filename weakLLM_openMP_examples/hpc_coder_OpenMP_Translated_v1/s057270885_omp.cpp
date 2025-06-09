#include <cstdio>
#include <omp.h>

void solvex(int x, int y){
	if(x > 9)return ;
	printf("%dx%d=%d\n",y,x,x*y);
	solvex(x+1,y);
}

void solvey(int y){
	if(y > 9)return ;
	#pragma omp parallel
	{
		solvex(1, y);
		solvey(y+1);
	}
}

int main(){
	solvey(1);
	return 0;
}