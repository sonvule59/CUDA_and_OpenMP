#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
#define FOR(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

__global__ void kernel(int *a, int *b, int *c){
	int i = threadIdx.x;
	a[i] = i;
	b[i] = i;
	c[i] = i;
}

int main(){
	int *a, *b, *c;
	cudaMalloc((void **)&a, 9*sizeof(int));
	cudaMalloc((void **)&b, 9*sizeof(int));
	cudaMalloc((void **)&c, 9*sizeof(int));
	kernel<<<1,9>>>(a, b, c);
	cudaDeviceSynchronize();
	rep(i,9){
		printf("%dx%d=%d\n",i+1,i+1,(i+1)*(i+1));
	}
	cudaFree(a);
	cudaFree(b);
	cudaFree(c);
	return 0;
}