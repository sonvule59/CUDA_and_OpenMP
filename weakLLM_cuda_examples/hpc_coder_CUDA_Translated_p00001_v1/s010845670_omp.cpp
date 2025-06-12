c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

__global__ void sort_kernel(int *h, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx < n) {
    for (int i = idx + 1; i < n; i++) {
      if (h[idx] > h[i]) {
        swap(h[idx], h[i]);
      }
    }
  }
}

int main() {
  vector<int> h(10);
  for(int i=0;i<10;++i)
	cin >> h[i];
  int *d_h;
  cudaMalloc((void **)&d_h, h.size() * sizeof(int));
  cudaMemcpy(d_h, h.data(), h.size() * sizeof(int), cudaMemcpyHostToDevice);
  int n = h.size();
  int threadsPerBlock = 256;
  int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
  sort_kernel<<<blocksPerGrid, threadsPerBlock>>>(d_h, n);
  cudaMemcpy(h.data(), d_h, h.size() * sizeof(int), cudaMemcpyDeviceToHost);
  sort(h.begin(), h.end());
  for(int i=0;i<3;++i)
	cout << h[9-i] << endl;
  cudaFree(d_h);
  return 0;
}