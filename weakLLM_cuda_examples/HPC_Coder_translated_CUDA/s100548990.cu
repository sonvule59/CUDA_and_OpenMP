#include <stdio.h>

__global__ void multiply(int *m, int *n, int *q) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < 100) {
		q[idx] = m[idx] * n[idx];
	}
}

int main() {
	int m[100], n[100], q[100];

	for(int i=0; i<100; i++) {
		m[i] = i+1;
		n[i] = i+1;
	}

	multiply<<<1,100>>>(m, n, q);

	for(int i=0; i<100; i++) {
		printf("%d x %d = %d\n", m[i], n[i], q[i]);
	}

	return 0;
}