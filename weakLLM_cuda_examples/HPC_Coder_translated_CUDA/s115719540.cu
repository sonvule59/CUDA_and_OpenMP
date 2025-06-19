#include <stdio.h>
#include <stdlib.h>

__global__ void kernel(int *a, int *b) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	a[idx] = b[idx];
}

int main() {
	int *a, *b;
	int n = 10;
	a = (int *)malloc(n * sizeof(int));
	b = (int *)malloc(n * sizeof(int));

	REP(i, n) {
		a[i] = i;
		b[i] = i * i;
	}

	kernel<<<1, n>>>(a, b);

	REP(i, n) {
		printf("%d x %d = %d\n", a[i], a[i], b[i]);
	}

	free(a);
	free(b);

	return 0;
}