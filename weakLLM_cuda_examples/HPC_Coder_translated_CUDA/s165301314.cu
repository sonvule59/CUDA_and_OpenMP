#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<deque>
#include<cstring>
#include<climits>
#include<cassert>
#include<cctype>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

__global__ void kernel(int *a, int *b) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx < 9) {
    a[idx] = (idx+1)*(idx+1);
    printf("%d x %d = %d\n", idx+1, idx+1, (idx+1)*(idx+1));
  }
}

int main() {
  int *a, *b;
  cudaMalloc((void **)&a, 9*sizeof(int));
  cudaMalloc((void **)&b, 9*sizeof(int));

  kernel<<<1,9>>>(a, b);

  cudaDeviceSynchronize();

  cudaFree(a);
  cudaFree(b);

  return 0;
}