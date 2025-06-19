#include<stdio.h>
__global__ void print_table(int start, int end){
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if(i >= start && i <= end){
		for(int j = 1 ; j <= 9 ; ++j)
		printf("%dx%d=%d\n",i,j,i*j);
	}
}

int main(){
	int start = 1, end = 9;
	print_table<<<1,10>>>(start, end);
	cudaDeviceSynchronize();
	return 0;
}