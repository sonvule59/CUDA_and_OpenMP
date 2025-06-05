#include <stdio.h>

__global__ void print_table(int *table) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx < 100) {
    printf("%dx%d=%d\n", idx / 10, idx % 10, table[idx]);
  }
}

int main(void) {
  int table[100];
  for (int i = 0; i < 100; i++) {
    table[i] = (i / 10) * (i % 10) * (i / 10) * (i % 10);
  }

  int *d_table;
  cudaMalloc((void **)&d_table, 100 * sizeof(int));
  cudaMemcpy(d_table, table, 100 * sizeof(int), cudaMemcpyHostToDevice);

  print_table<<<1, 100>>>(d_table);

  cudaDeviceSynchronize();
  cudaFree(d_table);

  return 0;
}