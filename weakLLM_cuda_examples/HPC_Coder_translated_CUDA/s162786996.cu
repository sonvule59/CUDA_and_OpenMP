#include <stdio.h>
#include <stdlib.h>

__global__ void print_table(int start, int end) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx >= start && idx <= end) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				printf("%d x %d = %d\n", i, j, i*j);
			}
		}
	}
}

int main() {
	int start = 1;
	int end = 9;
	int blockSize = 25;
	int numBlocks = (end - start + 1 + blockSize - 1) / blockSize;
	print_table<<<numBlocks, blockSize>>>(start, end);
	cudaDeviceSynchronize();
	return 0;
}