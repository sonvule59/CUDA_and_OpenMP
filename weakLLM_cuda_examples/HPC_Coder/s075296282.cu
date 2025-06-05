#include<stdio.h>
__global__ void multiply(int *a, int *b, int *c) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < 10) {
		c[idx] = a[idx] * b[idx];
	}
}

int main() {
	int a[10], b[10], c[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i + 1;
		b[i] = i + 1;
	}
	int *d_a, *d_b, *d_c;
	cudaMalloc((void **)&d_a, 10 * sizeof(int));
	cudaMalloc((void **)&d_b, 10 * sizeof(int));
	cudaMalloc((void **)&d_c, 10 * sizeof(int));
	cudaMemcpy(d_a, a, 10 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, 10 * sizeof(int), cudaMemcpyHostToDevice);
	multiply<<<1, 10>>>(d_a, d_b, d_c);
	cudaMemcpy(c, d_c, 10 * sizeof(int), cudaMemcpyDeviceToHost);
	for (int i = 0; i < 10; i++) {
		printf("%d x %d = %d\n", a[i], b[i], c[i]);
	}
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
	return 0;
}