c++
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

__global__ void sort_array(int *m, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        for (int i = idx + 1; i < n; i++) {
            if (m[idx] < m[i]) {
                swap(m[idx], m[i]);
            }
        }
    }
}

int main() {
    int m[10];
    for (int i = 0; i < 10; i++) {
        scanf(" %d", &m[i]);
    }

    int *d_m;
    cudaMalloc((void **)&d_m, 10 * sizeof(int));
    cudaMemcpy(d_m, m, 10 * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
    sort_array<<<blocksPerGrid, threadsPerBlock>>>(d_m, 10);

    int *h_m = (int *)malloc(10 * sizeof(int));
    cudaMemcpy(h_m, d_m, 10 * sizeof(int), cudaMemcpyDeviceToHost);

    sort(h_m, h_m + 3, greater<int>());

    for (int i = 0; i < 3; i++) {
        printf("%d\n", h_m[i]);
    }

    cudaFree(d_m);
    free(h_m);

    return 0;
}