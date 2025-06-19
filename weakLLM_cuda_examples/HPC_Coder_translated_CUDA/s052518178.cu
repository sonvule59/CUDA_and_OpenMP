#include<bits/stdc++.h>
using namespace std;

__global__ void kernel(int *a, int *b){
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if(idx<9){
		for(int c=0;c<9;c++)printf("%d*%d=%d\n",idx+1,c+1,(idx+1)*(c+1));
	}
}

int main(){
	int *a, *b;
	cudaMalloc((void **)&a, sizeof(int));
	cudaMalloc((void **)&b, sizeof(int));

	kernel<<<1,9>>>(a, b);

	cudaFree(a);
	cudaFree(b);

	return 0;
}