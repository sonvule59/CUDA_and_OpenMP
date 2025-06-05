#include<iostream>
using namespace std;

__global__ void multiply(int *a, int *b, int *c, int n) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < n) {
		c[idx] = a[idx] * b[idx];
	}
}

int main() {
	int n1, n2;
	int *a, *b, *c;

	// Allocate memory on the GPU
	cudaMalloc((void **)&a, n1 * sizeof(int));
	cudaMalloc((void **)&b, n2 * sizeof(int));
	cudaMalloc((void **)&c, n1 * n2 * sizeof(int));

	// Copy data from host to device
	cudaMemcpy(a, a_host, n1 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(b, b_host, n2 * sizeof(int), cudaMemcpyHostToDevice);

	// Launch the kernel
	multiply<<<1, n1>>>(a, b, c, n1 * n2);

	// Copy data from device to host
	cudaMemcpy(c_host, c, n1 * n2 * sizeof(int), cudaMemcpyDeviceToHost);

	// Free memory
	cudaFree(a);
	cudaFree(b);
	cudaFree(c);

	return 0;
}