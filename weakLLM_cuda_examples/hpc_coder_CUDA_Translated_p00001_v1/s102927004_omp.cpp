#include <stdio.h>

__global__ void sort(int *m, int n) {
    int i = threadIdx.x;
    int j = threadIdx.y;
    int t;
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            if (m[i * n + l] < m[j * n + l]) {
                t = m[i * n + l];
                m[i * n + l] = m[j * n + l];
                m[j * n + l] = t;
            }
        }
    }
}

int main() {
    int m[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &m[i]);
    }
    int n = 10;
    int *d_m;
    cudaMalloc((void **)&d_m, n * n * sizeof(int));
    cudaMemcpy(d_m, m, n * n * sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1, 1>>>(d_m, n);
    cudaMemcpy(m, d_m, n * n * sizeof(int), cudaMemcpyDeviceToHost);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", m[i]);
    }
    cudaFree(d_m);
    return 0;
}