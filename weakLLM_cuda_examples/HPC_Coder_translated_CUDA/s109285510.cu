#include <stdio.h>

__global__ void multiply(int *m, int *n, int *result) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < 100) {
		result[idx] = m[idx] * n[idx];
	}
}

int main(int argc, char *argv[]) {
	int m[100], n[100], result[100];
	for (int i = 0; i < 100; i++) {
		m[i] = i + 1;
		n[i] = i + 1;
	}

	int *d_m, *d_n, *d_result;
	cudaMalloc((void **)&d_m, 100 * sizeof(int));
	cudaMalloc((void **)&d_n, 100 * sizeof(int));
	cudaMalloc((void **)&d_result, 100 * sizeof(int));

	cudaMemcpy(d_m, m, 100 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_n, n, 100 * sizeof(int), cudaMemcpyHostToDevice);

	multiply<<<1, 100>>>(d_m, d_n, d_result);

	cudaMemcpy(result, d_result, 100 * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < 100; i++) {
		printf("%d x %d = %d\n", m[i], n[i], result[i]);
	}

	cudaFree(d_m);
	cudaFree(d_n);
	cudaFree(d_result);

	return 0;
}