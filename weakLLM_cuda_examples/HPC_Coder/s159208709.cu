#include<iostream>
using namespace std;

__global__ void multiply(int *a, int *b, int *c, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        c[idx] = a[idx] * b[idx];
    }
}

int main() {
    int n = 10;
    int *a, *b, *c;
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    c = (int *)malloc(n * sizeof(int));

    // Initialize a and b arrays
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    // Allocate memory on the GPU
    int *d_a, *d_b, *d_c;
    cudaMalloc((void **)&d_a, n * sizeof(int));
    cudaMalloc((void **)&d_b, n * sizeof(int));
    cudaMalloc((void **)&d_c, n * sizeof(int));

    // Copy data from host to device
    cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, n * sizeof(int), cudaMemcpyHostToDevice);

    // Launch the kernel
    multiply<<<1, n>>>(d_a, d_b, d_c, n);

    // Copy data from device to host
    cudaMemcpy(c, d_c, n * sizeof(int), cudaMemcpyDeviceToHost);

    // Free memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << a[i