#include<iostream>
using namespace std;

__global__ void printTable(int *table){
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	if(index < 10){
		for(int jndex = 1 ; jndex <= 9 ; jndex++){
			printf("%d x %d = %d\n", index, jndex, index*jndex);
		}
	}
}

int main(){
	int *table;
	cudaMalloc((void **)&table, sizeof(int)*10*10);
	printTable<<<1,10>>>(table);
	cudaDeviceSynchronize();
	cudaFree(table);
}