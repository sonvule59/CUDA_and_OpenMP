#include<stdio.h>
__global__ void kernel(int *x, int *y){
	int i, j;
	for(i=0; i<9; i++){
	y[i]=0;
	++x[0];
	for(j=0; j<9; j++){
	++y[i];
	printf("%dx%d=%d\n",x[0],y[i],x[0]*y[i]);
	};
	};
}

int main(){
	int x=0,y=0,i,j;
	int *x_d, *y_d;
	cudaMalloc((void **)&x_d, sizeof(int));
	cudaMalloc((void **)&y_d, sizeof(int));
	cudaMemcpy(x_d, &x, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(y_d, &y, sizeof(int), cudaMemcpyHostToDevice);
	kernel<<<1,1>>>(x_d, y_d);
	cudaMemcpy(&x, x_d, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&y, y_d, sizeof(int), cudaMemcpyDeviceToHost);
	cudaFree(x_d);
	cudaFree(y_d);
	return 0;
}