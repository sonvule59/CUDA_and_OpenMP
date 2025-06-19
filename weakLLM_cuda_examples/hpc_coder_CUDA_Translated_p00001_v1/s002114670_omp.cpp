
#include <algorithm>
#include <iostream>
#include <vector>

global__ void sort_hills(int *hills, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        for (int i = idx + 1; i < n; ++i) {
            if (hills[idx] < hills[i]) {
                std::swap(hills[idx], hills[i]);
            }
        }
    }
}

int main() {
    std::vector<int> hills;
    
    int n;
    while (std::cin >> n) {
        hills.push_back(n);
    }
    
    int *d_hills;
    cudaMalloc((void **)&d_hills, hills.size() * sizeof(int));
    cudaMemcpy(d_hills, hills.data(), hills.size() * sizeof(int), cudaMemcpyHostToDevice);
    
    int threads_per_block = 256;
    int blocks_per_grid = (hills.size() + threads_per_block - 1) / threads_per_block;
    sort_hills<<<blocks_per_grid, threads_per_block>>>(d_hills, hills.size());
    
    cudaMemcpy(hills.data(), d_hills, hills.size() * sizeof(int), cudaMemcpyDeviceToHost);
    
    std::sort(hills.begin(), hills.end(), std::greater<int>());
    
    for (int i = 0; i < 3; ++i) {
        std::cout << hills[i] << std::endl;
    }
    
    cudaFree(d_hills);
    
    return 0;
}