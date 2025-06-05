#include <stdio.h>

__global__ void solvex(int x, int y){
	if(x > 9)return ;
	printf("%dx%d=%d\n",y,x,x*y);
	solvex(x+1,y);
}

__global__ void solvey(int y){
	if(y > 9)return ;
	solvex(1, y);
	solvey(y+1);
}

int main(){
	solvey<<<1,1>>>(1);
	cudaDeviceSynchronize();
	return 0;
}