#include <stdio.h>

__global__ void multiply(int *a, int *b, int *c) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	if (i < 10 && j < 10) {
		c[i * 10 + j] = a[i] * b[j];
	}
}

int main(int argc, char const *argv[])
{
	int a[10][10], b[10][10], c[10][10];
	int i, j;
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			a[i][j] = i+1;
			b[i][j] = j+1;
		}
	}

	dim3 threadsPerBlock(16, 16);
	dim3 numBlocks((10+threadsPerBlock.x-1)/threadsPerBlock.x, (10+threadsPerBlock.y-1)/threadsPerBlock.y);
	multiply<<<numBlocks, threadsPerBlock>>>(a, b, c);

	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			printf("%dx%d=%d\n", i+1, j+1, c[i][j]);
		}
	}
	return 0;
}