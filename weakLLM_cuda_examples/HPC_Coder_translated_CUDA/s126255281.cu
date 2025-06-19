#include <stdio.h>

__global__ void kernel(void)
{
	int i = threadIdx.x;
	int j = threadIdx.y;

	printf("%d x %d = %d\n", i, j, i * j);
}

int main(void)
{
	kernel<<<1, 1>>>();
	cudaDeviceSynchronize();
	return 0;
}