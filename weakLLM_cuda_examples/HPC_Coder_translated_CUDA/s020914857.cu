#include <stdio.h>

__global__ void print_table(int m, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx < m) {
    for (int i = 1; i <= n; i++) {
      printf("%d x %d = %d\n", idx, i, idx * i);
    }
  }
}

int main() {
  int m, n;
  m = 1;
  n = 1;

  while (true) {
    if (n == 10) {
      m++;
      n = 1;
    }
    if (m == 10) break;

    print_table<<<1, 1>>>(m, n);
    cudaDeviceSynchronize();
    n++;
  }
  return 0;
}