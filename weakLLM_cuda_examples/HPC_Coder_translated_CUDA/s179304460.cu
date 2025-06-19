#include<iostream>
using namespace std;

__global__ void print_table(int *table){
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	if (i < 9 && j < 9){
		printf("%d x %d = %d\n", i + 1, j + 1, (i+1)*(j+1));
	}
}

int main(){
	int table[9][9];
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			table[i][j] = (i+1)*(j+1);
		}
	}

	int *d_table;
	cudaMalloc((void **)&d_table, 9*9*sizeof(int));
	cudaMemcpy(d_table, table, 9*9*sizeof(int), cudaMemcpyHostToDevice);

	dim3 threadsPerBlock(9, 9);
	dim3 numBlocks((9+threadsPerBlock.x-1)/threadsPerBlock.x, (9+threadsPerBlock.y-1)/threadsPerBlock.y);
	print_table<<<numBlocks, threadsPerBlock>>>(d_table);

	cudaDeviceSynchronize();
	cudaFree(d_table);

	return 0;
}