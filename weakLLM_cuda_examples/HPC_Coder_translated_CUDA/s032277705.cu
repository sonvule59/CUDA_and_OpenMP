#include <stdio.h>

__global__ void kernel(int *seki) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int k = blockIdx.y * blockDim.y + threadIdx.y;
	
	if(i<=9 && k<=9) {
		*seki = i * k;
		printf("%d", i);
		printf("x");
		printf("%d", k);
		printf("=");
		printf("%d\n", *seki);
	}
}

int main() {
	int seki;
	int *d_seki;
	
	// Allocate memory on the GPU
	cudaMalloc((void **)&d_seki, sizeof(int));
	
	// Launch the kernel
	kernel<<<dim3(9,9), dim3(1,1)>>>(d_seki);
	
	// Copy the result from the GPU to the CPU
	cudaMemcpy(&seki, d_seki, sizeof(int), cudaMemcpyDeviceToHost);
	
	// Free memory
	cudaFree(d_seki);
	
	return 0;
}