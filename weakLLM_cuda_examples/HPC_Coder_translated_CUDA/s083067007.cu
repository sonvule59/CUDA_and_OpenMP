#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

__global__ void print_table(int n) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < n) {
		for_(j,1,10) {
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}
}

int main() {
	int n = 10;
	print_table<<<1,n>>>(n);
	cudaDeviceSynchronize();
}