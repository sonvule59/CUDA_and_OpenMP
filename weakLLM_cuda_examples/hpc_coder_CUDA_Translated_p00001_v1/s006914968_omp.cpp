c++
#include<iostream>
using namespace std;
__global__ void sort(int *m, int n) {
    int i = threadIdx.x;
    int j = i + blockIdx.x * blockDim.x;
    int tmp;
    for (int k = i; k < n; k += blockDim.x) {
        for (int l = k + 1; l < n; l++) {
            if (m[k] <= m[l]) {
                tmp = m[k];
                m[k] = m[l];
                m[l] = tmp;
            }
        }
    }
}
int main() {
    int m[10];
    int i;
    for (i = 0; i < 10; i++) {
        cin >> m[i];
    }
    int *d_m;
    cudaMalloc((void **)&d_m, 10 * sizeof(int));
    cudaMemcpy(d_m, m, 10 * sizeof(int), cudaMemcpyHostToDevice);
    int threadsPerBlock = 256;
    int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
    sort<<<blocksPerGrid, threadsPerBlock>>>(d_m, 10);
    cudaMemcpy(m, d_m, 10 * sizeof(int), cudaMemcpyDeviceToHost);
    for (i = 0; i < 3; i++)
        cout << m[i] << endl;
    cudaFree(d_m);
    return 0;
}