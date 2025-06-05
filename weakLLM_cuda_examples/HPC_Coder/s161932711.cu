#include<stdio.h>

__global__ void multiply(int *a, int *b, int *c, int n) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	if (i < n) {
		c[i] = a[i] * b[i];
	}
}

int main() {
	int n = 10;
	int *a, *b, *c;
	a = (int *)malloc(n * sizeof(int));
	b = (int *)malloc(n * sizeof(int));
	c = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		a[i] = i;
		b[i] = i;
	}

	int *d_a, *d_b, *d_c;
	cudaMalloc((void **)&d_a, n * sizeof(int));
	cudaMalloc((void **)&d_b, n * sizeof(int));
	cudaMalloc((void **)&d_c, n * sizeof(int));

	cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, n * sizeof(int), cudaMemcpyHostToDevice);

	multiply<<<1, n>>>(d_a, d_b, d_c, n);

	cudaMemcpy(c, d_c, n * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < n; i++) {
		printf("%d * %d = %d\n", a[i], b[i], c[i]);
	}

	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);

	free(a);
	free(b);
	free(c);

	return 0;
}