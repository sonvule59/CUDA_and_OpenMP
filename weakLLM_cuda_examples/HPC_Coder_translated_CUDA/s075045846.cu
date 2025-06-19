#include <stdio.h>

__global__ void print_table(int minNum, int maxNum) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  int j = blockIdx.y * blockDim.y + threadIdx.y;

  if (i >= minNum && i <= maxNum && j >= minNum && j <= maxNum) {
    printf("%d x %d = %d\n", i, j, i * j);
  }
}

int main(void) {
  const int minNum = 1;
  const int maxNum = 9;

  int blockSize = 16;
  int numBlocks = (maxNum - minNum + 1) / blockSize;

  print_table<<<numBlocks, blockSize>>>(minNum, maxNum);

  cudaDeviceSynchronize();

  return 0;
}