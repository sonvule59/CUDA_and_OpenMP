#include <stdio.h>
#include <iostream>
using namespace std;
__global__ void findMax(int *height, int *max) {
 int idx = threadIdx.x + blockIdx.x * blockDim.x;
 if (idx < 10) {
  int tmp = 0;
  for (int n = 0; n < 10; ++n) {
   if (tmp < height[n]) {
    tmp = height[n];
    idx = n;
   }
  }
  max[idx] = tmp;
  height[idx] = 0;
 }
}
int main() {
 int height[10], max[3];
 for (int i = 0; i < 10; ++i) cin >> height[i];
 int *d_height, *d_max;
 cudaMalloc((void **)&d_height, 10 * sizeof(int));
 cudaMalloc((void **)&d_max, 3 * sizeof(int));
 cudaMemcpy(d_height, height, 10 * sizeof(int), cudaMemcpyHostToDevice);
 findMax<<<1, 10>>>(d_height, d_max);
 cudaMemcpy(max, d_max, 3 * sizeof(int), cudaMemcpyDeviceToHost);
 for (int i = 0; i < 3; ++i) cout << max[i] << "\n";
 cudaFree(d_height);
 cudaFree(d_max);
 return 0;
}