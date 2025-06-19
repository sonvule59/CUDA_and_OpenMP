#include <stdio.h>

__global__ void print_table(int ans) {

	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int n = blockIdx.y * blockDim.y + threadIdx.y;

	if (i < 9 && n < 9) {
		ans = (n + 1) * (i + 1);
		printf("%d x %d = %d\n", i + 1, n + 1, ans);
	}

}

int main() {

	int ans = 0;

	dim3 threadsPerBlock(9, 9);
	dim3 numBlocks(1, 1);

	print_table<<<numBlocks, threadsPerBlock>>>(ans);

	cudaDeviceSynchronize();

	return 0;

}