c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

__global__ void sort_vals(int *vals, int dataNum) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx < dataNum) {
    for (int i = idx + 1; i < dataNum; i++) {
      if (vals[idx] < vals[i]) {
        std::swap(vals[idx], vals[i]);
      }
    }
  }
}

int main(void)
{
  const int dataNum = 10;

  std::vector<int> vals;
  for (int i = 0; i < dataNum; i++) {
    int newVal;
    std::cin >> newVal;
    vals.push_back(newVal);
  }

  int *vals_d;
  cudaMalloc((void **)&vals_d, dataNum * sizeof(int));
  cudaMemcpy(vals_d, vals.data(), dataNum * sizeof(int), cudaMemcpyHostToDevice);

  int blockSize = 256;
  int numBlocks = (dataNum + blockSize - 1) / blockSize;
  sort_vals<<<numBlocks, blockSize>>>(vals_d, dataNum);

  cudaMemcpy(vals.data(), vals_d, dataNum * sizeof(int), cudaMemcpyDeviceToHost);

  std::sort(vals.begin(), vals.end(), std::greater<int>());

  const int outputDataNum = 3;
  
  for (int i = 0; i < outputDataNum; i++) {
    std::cout << vals[i] << std::endl;
  }

  cudaFree(vals_d);

  return 0;
}