#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

__global__ void kernel(int *a, int *b)
{
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if(idx < 100)
	{
		a[idx] = idx * idx;
		b[idx] = idx * idx * idx;
	}
}

int main()
{
	int *a, *b;
	cudaMalloc((void **)&a, 100 * sizeof(int));
	cudaMalloc((void **)&b, 100 * sizeof(int));

	kernel<<<1,100>>>(a, b);

	cudaDeviceSynchronize();

	for(int i = 0;i < 100;i++)
	{
		printf("%d^2=%d\n",i,a[i]);
		printf("%d^3=%d\n",i,b[i]);
	}

	cudaFree(a);
	cudaFree(b);

	return 0;
}