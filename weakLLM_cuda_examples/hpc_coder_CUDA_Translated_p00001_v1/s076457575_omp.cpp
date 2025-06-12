c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)

__global__ void sort_kernel(int *data, int n){
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if(idx < n){
		sort(data + idx, data + idx + 1);
	}
}

int main(){

	vector<int> data(10);

	rep(i,10){
		cin >> data[i];
	}

	int *d_data;
	cudaMalloc((void **)&d_data, data.size() * sizeof(int));
	cudaMemcpy(d_data, data.data(), data.size() * sizeof(int), cudaMemcpyHostToDevice);

	int threadsPerBlock = 256;
	int blocksPerGrid = (data.size() + threadsPerBlock - 1) / threadsPerBlock;
	sort_kernel<<<blocksPerGrid, threadsPerBlock>>>(d_data, data.size());

	cudaDeviceSynchronize();

	rep(i,3){
		cout << d_data[9 - i] << endl;
	}

	cudaFree(d_data);

	return 0;
}