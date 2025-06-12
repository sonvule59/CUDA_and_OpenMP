c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

__global__ void sort_array(int *a, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        for (int i = idx + 1; i < n; i++) {
            if (a[idx] < a[i]) {
                swap(a[idx], a[i]);
            }
        }
    }
}

int main() {
    int a[10], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int *d_a;
    cudaMalloc((void **)&d_a, n * sizeof(int));
    cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
    sort_array<<<blocksPerGrid, threadsPerBlock>>>(d_a, n);

    cudaMemcpy(a, d_a, n * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 9; i >= 7; i--) {
        cout << a[i] << endl;
    }

    cudaFree(d_a);
    return 0;
}