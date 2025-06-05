#include<iostream>

using namespace std;

__global__ void kernel(int *a, int *b) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	int kake = i * j;
	a[i] = kake;
	b[j] = kake;
}

int main() {
	int a[10][10];
	int b[10][10];

	dim3 threadsPerBlock(16, 16);
	dim3 numBlocks((10+threadsPerBlock.x-1)/threadsPerBlock.x, (10+threadsPerBlock.y-1)/threadsPerBlock.y);

	kernel<<<numBlocks, threadsPerBlock>>>(a, b);

	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			cout << a[i][j] << "x" << b[j][i] << "=" << a[i][j] * b[j][i] << endl;
		}
	}
	return 0;
}