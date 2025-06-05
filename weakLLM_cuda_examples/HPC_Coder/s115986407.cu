#include <stdio.h>

__global__ void kernel(int *a, int *b, int *c) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	if (i < 9 && j < 9) {
		int a = i + 1;
		int b = j + 1;
		c[i * 9 + j] = a * b;
	}
}

int main() {
	int a[9][9];
	int b[9][9];
	int c[9][9];

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			a[i][j] = i + 1;
			b[i][j] = j + 1;
		}
	}

	kernel<<<dim3(3, 3), dim3(3, 3)>>>(a, b, c);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%dx%d=%d\n", a[i][j], b[i][j], c[i][j]);
		}
	}

	return 0;
}