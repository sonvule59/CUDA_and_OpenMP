#include <stdio.h>

__global__ void multiply(int *x, int *y, int *z, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        z[idx] = x[idx] * y[idx];
    }
}

int main() {
    int x[9], y[9], z[9];
    int n = 9;

    for (int i = 0; i < n; i++) {
        x[i] = i + 1;
        y[i] = i + 1;
    }

    int *d_x, *d_y, *d_z;
    cudaMalloc((void **)&d_x, n * sizeof(int));
    cudaMalloc((void **)&d_y, n * sizeof(int));
    cudaMalloc((void **)&d_z, n * sizeof(int));

    cudaMemcpy(d_x, x, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, n * sizeof(int), cudaMemcpyHostToDevice);

    multiply<<<1, n>>>(d_x, d_y, d_z, n);

    cudaMemcpy(z, d_z, n * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < n; i++) {
        printf("%d x %d = %d\n", x[i], y[i], z[i]);
    }

    cudaFree(d_x);
    cudaFree(d_y);
    cudaFree(d_z);

    return 0;
}