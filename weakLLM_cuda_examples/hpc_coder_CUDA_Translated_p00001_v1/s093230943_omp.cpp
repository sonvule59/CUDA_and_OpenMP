c++
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

__global__ void sort_kernel(int *v, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        for (int i = idx + 1; i < n; i++) {
            if (v[idx] < v[i]) {
                swap(v[idx], v[i]);
            }
        }
    }
}

int main(void) {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }
    int *d_v;
    cudaMalloc((void **)&d_v, v.size() * sizeof(int));
    cudaMemcpy(d_v, v.data(), v.size() * sizeof(int), cudaMemcpyHostToDevice);
    int n = v.size();
    int threads_per_block = 256;
    int blocks_per_grid = (n + threads_per_block - 1) / threads_per_block;
    sort_kernel<<<blocks_per_grid, threads_per_block>>>(d_v, n);
    cudaMemcpy(v.data(), d_v, v.size() * sizeof(int), cudaMemcpyDeviceToHost);
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < 3; i++) {
        printf("%d\n", v[i]);
    }
    cudaFree(d_v);
}