#include<stdio.h>

__global__ void multiply(int *a, int *b, int *c, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        c[idx] = a[idx] * b[idx];
    }
}

int main() {
    int a[10], b[10], c[10];
    int n = 10;

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    int *d_a, *d_b, *d_c;
    cudaMalloc((void **)&d_a, n * sizeof(int));
    cudaMalloc((void **)&d_b, n * sizeof(int));
    cudaMalloc((void **)&d_c, n * sizeof(int));

    cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, n * sizeof(int), cudaMemcpyHostToDevice);

    multiply<<<1, n>>>(d_a, d_b, d_c, n);

    cudaMemcpy(c, d_c, n * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < n; i++) {
        printf("%d x %d = %d\n", a[i], b[i], c[i]);
    }

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}