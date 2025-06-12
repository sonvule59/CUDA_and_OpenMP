c++
#include<iostream>
using namespace std;

__global__ void sort(int *mountain, int *first, int *second, int *third) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < 10) {
		if (*first <= mountain[idx]) {
			*third = *second;
			*second = *first;
			*first = mountain[idx];
		}
		else if (mountain[idx] <= *first && mountain[idx] >= *second) {
			*third = *second;
			*second = mountain[idx];
		}
		else if (mountain[idx] <= *second && mountain[idx] >= *third) {
			*third = mountain[idx];
		}
	}
}

int main() {
	int mountain[10], first = 0, second = 0, third = 0;
	for (int j = 0; j < 10; j++) {
		mountain[j] = 0;
	}

	for (int i = 0; i < 10; i++) {
		cin >> mountain[i];
	}

	int *d_mountain, *d_first, *d_second, *d_third;
	cudaMalloc((void **)&d_mountain, 10 * sizeof(int));
	cudaMalloc((void **)&d_first, sizeof(int));
	cudaMalloc((void **)&d_second, sizeof(int));
	cudaMalloc((void **)&d_third, sizeof(int));

	cudaMemcpy(d_mountain, mountain, 10 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_first, &first, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_second, &second, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_third, &third, sizeof(int), cudaMemcpyHostToDevice);

	sort<<<1, 10>>>(d_mountain, d_first, d_second, d_third);

	cudaMemcpy(&first, d_first, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&second, d_second, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&third, d_third, sizeof(int), cudaMemcpyDeviceToHost);

	cout << first << "\n" << second << "\n" << third << endl;

	cudaFree(d_mountain);
	cudaFree(d_first);
	cudaFree(d_second);
	cudaFree(d_third);

	return 0;
}