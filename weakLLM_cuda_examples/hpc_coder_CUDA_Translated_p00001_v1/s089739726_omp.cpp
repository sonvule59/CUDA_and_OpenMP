c++
#include<iostream>
using namespace std;
__global__ void sort(double *h, int n) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < n) {
		double h1, h2, h3;
		h1 = -1;
		h2 = -1;
		h3 = -1;
		for (int i = 0; i < n; i++) {
			if (h[i] > h1) {
				h3 = h2;
				h2 = h1;
				h1 = h[i];
			}
			else if (h[i] > h2) {
				h3 = h2;
				h2 = h[i];
			}
			else if (h[i] > h3) {
				h3 = h[i];
			}
		}
		h[idx] = h1;
		h[idx + 1] = h2;
		h[idx + 2] = h3;
	}
}
int main() {
	double h[10];
	for (int i = 0; i < 10; i++) {
		cin >> h[i];
	}
	double *d_h;
	cudaMalloc((void **)&d_h, 10 * sizeof(double));
	cudaMemcpy(d_h, h, 10 * sizeof(double), cudaMemcpyHostToDevice);
	int threadsPerBlock = 256;
	int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
	sort<<<blocksPerGrid, threadsPerBlock>>>(d_h, 10);
	cudaMemcpy(h, d_h, 10 * sizeof(double), cudaMemcpyDeviceToHost);
	for (int i = 0; i < 10; i++) {
		cout << h[i] << endl;
	}
	cudaFree(d_h);
	return 0;
}