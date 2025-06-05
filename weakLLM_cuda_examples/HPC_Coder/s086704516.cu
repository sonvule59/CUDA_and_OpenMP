#include <stdio.h>

#define pout(n)  printf ("%d\n", n)

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)

const int d4x[4] = {1, 0, -1, 0};
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };
 
typedef long long ll;

__global__ void kernel(int *a, int *b, int n) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  if (i < n) {
    a[i] = i * i;
    b[i] = i * i * i;
  }
}

int main() {
  int *a, *b;
  int n = 10;
  cudaMalloc((void **)&a, n * sizeof(int));
  cudaMalloc((void **)&b, n * sizeof(int));
  kernel<<<1, n>>>(a, b, n);
  cudaDeviceSynchronize();
  rep(i,0,n){
    printf("%dx%d=%d\n",i,i,a[i]);
    printf("%dx%d=%d\n",i,i,b[i]);
  }
  cudaFree(a);
  cudaFree(b);
  return 0;
}