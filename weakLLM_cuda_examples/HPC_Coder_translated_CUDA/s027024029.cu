#include <stdio.h>
#include <stdlib.h>

__global__ void kernel(int *a, int *b) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < 100) {
		a[idx] = idx;
		b[idx] = idx * 2;
	}
}

int main() {
	int *a, *b;
	int size = 100 * sizeof(int);
	a = (int *)malloc(size);
	b = (int *)malloc(size);

	kernel<<<1, 100>>>(a, b);

	REP(i, 100) {
		printf("%d x %d = %d\n", i, i, a[i] * b[i]);
	}

	free(a);
	free(b);

	return 0;
}