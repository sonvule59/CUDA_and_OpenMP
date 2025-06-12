c++
#include <algorithm>
#include <iostream>

__global__ void sort_array(int *h, int n) {
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	if (tid < n) {
		for (int i = tid; i < n; i += blockDim.x * gridDim.x) {
			for (int j = i + 1; j < n; j++) {
				if (h[i] > h[j]) {
					int temp = h[i];
					h[i] = h[j];
					h[j] = temp;
				}
			}
		}
	}
}

int main() {
	int h[10];

	for (int i = 0; i < 10; i++)
		std::cin >> h[i];

	int *d_h;
	cudaMalloc((void **)&d_h, 10 * sizeof(int));
	cudaMemcpy(d_h, h, 10 * sizeof(int), cudaMemcpyHostToDevice);

	int threadsPerBlock = 256;
	int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
	sort_array<<<blocksPerGrid, threadsPerBlock>>>(d_h, 10);

	cudaMemcpy(h, d_h, 10 * sizeof(int), cudaMemcpyDeviceToHost);

	std::sort(h, h + 10);

	std::cout
		<< h[9] << std::endl
		<< h[8] << std::endl
		<< h[7] << std::endl;

	cudaFree(d_h);
}