#include<bits/stdc++.h>

using namespace std;

__global__ void sort_array(int *mount, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx < n) {
    for (int i = idx; i < n; i += blockDim.x * gridDim.x) {
      for (int j = i + 1; j < n; j++) {
        if (mount[i] > mount[j]) {
          int temp = mount[i];
          mount[i] = mount[j];
          mount[j] = temp;
        }
      }
    }
  }
}

int main() {
  int n;
  int mount[10] = {};

  for (int i = 0; i < 10; i++) {
    cin >> mount[i];
  }

  int *d_mount;
  cudaMalloc((void **)&d_mount, 10 * sizeof(int));
  cudaMemcpy(d_mount, mount, 10 * sizeof(int), cudaMemcpyHostToDevice);

  int threadsPerBlock = 256;
  int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
  sort_array<<<blocksPerGrid, threadsPerBlock>>>(d_mount, 10);

  cudaMemcpy(mount, d_mount, 10 * sizeof(int), cudaMemcpyDeviceToHost);

  for (int i = 9; i > 6; i--) {
    cout << mount[i] << endl;
  }

  cudaFree(d_mount);
  return 0;
}