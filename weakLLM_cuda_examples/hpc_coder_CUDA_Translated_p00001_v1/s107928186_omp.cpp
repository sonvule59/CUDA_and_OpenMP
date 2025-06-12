#include <stdio.h>

#define MAX_NUM	(10)

__global__ void 
sort(int *h)
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < MAX_NUM) {
		for (int j = MAX_NUM - 1; j > i; j--) {
			if (h[j] > h[j-1]) {
				int tmp = h[j];
				h[j] = h[j-1];
				h[j-1] = tmp;
			}
		}
	}
}

int
main(void)
{
	char line[80];
	int h[MAX_NUM] = { 0 };

 	for (int i = 0 ; i < 10; i++) {
		if (gets(line)) {
			if (sscanf(line, "%d", &(h[i])) != 1) {
				break;
			}
		}
 	}

	int *d_h;
	cudaMalloc((void **)&d_h, MAX_NUM * sizeof(int));
	cudaMemcpy(d_h, h, MAX_NUM * sizeof(int), cudaMemcpyHostToDevice);

	sort<<<1, MAX_NUM>>>(d_h);

	cudaMemcpy(h, d_h, MAX_NUM * sizeof(int), cudaMemcpyDeviceToHost);

	sort<<<1, MAX_NUM>>>(d_h);

	cudaMemcpy(h, d_h, MAX_NUM * sizeof(int), cudaMemcpyDeviceToHost);

 	for (int i = 0 ; i < 3; i++) {
 		printf("%d\n", h[i]);
 	}

	cudaFree(d_h);

	return 0;
}