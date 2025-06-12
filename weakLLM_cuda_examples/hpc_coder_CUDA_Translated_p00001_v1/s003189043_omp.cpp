c++
#include <cstdlib> 
#include <iostream>

using namespace std;

__global__ void cmp(int* a, int* b)
{
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < 10)
	{
		a[idx] = (*a < *b) ? 1 : ((*a > *b) ? -1 : 0);
	}
}

int main()
{
	int dat[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> dat[i];
	}

	int* d_dat;
	cudaMalloc((void**)&d_dat, 10 * sizeof(int));
	cudaMemcpy(d_dat, dat, 10 * sizeof(int), cudaMemcpyHostToDevice);

	cmp<<<1, 10>>>(d_dat, d_dat);

	cudaMemcpy(dat, d_dat, 10 * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < 3; i++)
	{
		cout << dat[i] << endl;
	}

	cudaFree(d_dat);

	return 0;
}