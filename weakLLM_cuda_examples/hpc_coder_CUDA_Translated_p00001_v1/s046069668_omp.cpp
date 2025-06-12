#include <stdio.h>
#include <stdlib.h>

__global__ void sort(int *h, int n) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	if (i < n) {
		int j = i;
		while (j > 0 && h[j] > h[j-1]) {
			int temp = h[j];
			h[j] = h[j-1];
			h[j-1] = temp;
			j--;
		}
	}
}

int main() {
	int h[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &h[i]);
	}

	int *d_h;
	cudaMalloc((void **)&d_h, 10 * sizeof(int));
	cudaMemcpy(d_h, h, 10 * sizeof(int), cudaMemcpyHostToDevice);

	int threadsPerBlock = 256;
	int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
	sort<<<blocksPerGrid, threadsPerBlock>>>(d_h, 10);

	int *h_sorted = (int *)malloc(10 * sizeof(int));
	cudaMemcpy(h_sorted, d_h, 10 * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", h_sorted[i]);
	}

	cudaFree(d_h);
	free(h_sorted);
	return 0;
}