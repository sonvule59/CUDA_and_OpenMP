#include <stdio.h>

__global__ void sort(int *arr, int len) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < len) {
		for (int j = 0; j < len; j++)
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
	}
}

int main() {
	const int len = 10;
	int arr[len];

	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	int *d_arr;
	cudaMalloc((void **)&d_arr, len * sizeof(int));
	cudaMemcpy(d_arr, arr, len * sizeof(int), cudaMemcpyHostToDevice);

	int threadsPerBlock = 256;
	int blocksPerGrid = (len + threadsPerBlock - 1) / threadsPerBlock;
	sort<<<blocksPerGrid, threadsPerBlock>>>(d_arr, len);

	cudaMemcpy(arr, d_arr, len * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = len - 1; len - 4 < i; i--)
		printf("%d\n", arr[i]);

	cudaFree(d_arr);
	return 0;
}