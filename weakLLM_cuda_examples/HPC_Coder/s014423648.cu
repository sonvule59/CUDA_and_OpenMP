#include <stdio.h>

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

__global__ void kernel(int *a, int *b)
{
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  int j = blockIdx.y * blockDim.y + threadIdx.y;
  if (i < 10 && j < 10) {
    printf("%dx%d=%d\n",i,j,i*j);
  }
}

int main()
{
  int a[10][10];
  int b[10][10];
  REP(i,10) REP(j,10) {
    a[i][j] = i*j;
    b[i][j] = i*j;
  }
  int *d_a, *d_b;
  cudaMalloc((void **)&d_a, 10*10*sizeof(int));
  cudaMalloc((void **)&d_b, 10*10*sizeof(int));
  cudaMemcpy(d_a, a, 10*10*sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, b, 10*10*sizeof(int), cudaMemcpyHostToDevice);
  dim3 threadsPerBlock(16, 16);
  dim3 numBlocks((10+threadsPerBlock.x-1)/threadsPerBlock.x, (10+threadsPerBlock.y-1)/threadsPerBlock.y);
  kernel<<<numBlocks, threadsPerBlock>>>(d_a, d_b);
  cudaMemcpy(a, d_a, 10*10*sizeof(int), cudaMemcpyDeviceToHost);
  cudaMemcpy(b, d_b, 10*