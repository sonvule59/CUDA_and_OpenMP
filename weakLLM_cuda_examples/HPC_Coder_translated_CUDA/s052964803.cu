#include<stdio.h>

__global__ void print_table(int *table) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < 81) {
		printf("%d x %d = %d\n", i / 9 + 1, i % 9 + 1, (i/9+1)*(i%9+1));
	}
}

int main() {
	int table[81];
	for (int i = 0; i < 81; i++) {
		table[i] = i;
	}

	print_table<<<1, 81>>>(table);

	return 0;
}