#include <stdio.h>

__global__ void sort(int *r, int h) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < 3) {
		if (h > r[idx]) {
			int temp = r[2];
			r[2] = r[1];
			r[1] = r[0];
			r[0] = h;
		} else if (h > r[1]) {
			r[2] = r[1];
			r[1] = h;
		} else if (h > r[2]) {
			r[2] = h;
		}
	}
}

int main() {
	int r[3] = {0, 0, 0};
	int h;

	for(int i = 0; i < 10; i++){
		scanf("%d", &h);
		sort<<<1, 1>>>(r, h);
	}

	for(int i = 0; i < 3; i++){
		printf("%d\n", r[i]);
	}

	return 0;
}