#include <stdio.h>

__global__ void print_table(int *table) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int k = blockIdx.y * blockDim.y + threadIdx.y;
	int l = i * k;
	printf("%d x %d = %d\n", i, k, l);
}

int main() {
	int table[10][10];
	for(int i = 0; i < 10; i++) {
		for(int k = 0; k < 10; k++) {
			table[i][k] = i * k;
		}
	}

	int *d_table;
	cudaMalloc((void **)&d_table, 10 * 10 * sizeof(int));
	cudaMemcpy(d_table, table, 10 * 10 * sizeof(int), cudaMemcpyHostToDevice);

	int threadsPerBlock = 16;
	int blocksPerGrid = (10 * 10 + threadsPerBlock - 1) / threadsPerBlock;
	print_table<<<blocksPerGrid, threadsPerBlock>>>(d_table);

	cudaDeviceSynchronize();
	cudaFree(d_table);
	return 0;
}