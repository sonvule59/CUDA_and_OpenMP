#include <stdio.h>
#include <stdlib.h>

__global__ void multiply(int *a, int *b, int *c) {
    int i = threadIdx.x;
    c[i] = a[i] * b[i];
}

int main() {
    int *a, *b, *c;
    int size = 9;

    // Allocate memory for arrays on the GPU
    cudaMalloc((void **)&a, size * sizeof(int));
    cudaMalloc((void **)&b, size * sizeof(int));
    cudaMalloc((void **)&c, size * sizeof(int));

    // Copy data from host to device
    for (int i = 0; i < size; i++) {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    // Launch the CUDA kernel
    multiply<<<1, size>>>(a, b, c);

    // Copy data from device to host
    for (int i = 0; i < size; i++) {
        printf("%d x %d = %d\n", a[i], b[i], c[i]);
    }

    // Free memory
    cudaFree(a);
    cudaFree(b);
    cudaFree(c);

    return 0;
}