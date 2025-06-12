#include <stdio.h>

__global__ void sort(int *x1, int *x2, int *x3, int *input, int s) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < s) {
        if (*x1 < input[idx]) {
            *x3 = *x2;
            *x2 = *x1;
            *x1 = input[idx];
        } else {
            if (*x2 < input[idx]) {
                *x3 = *x2;
                *x2 = input[idx];
            } else if (*x3 < input[idx]) *x3 = input[idx];
        }
    }
}

int main(void) {
    int x1 = 0, x2 = 0, x3 = 0, input, s;
    int *d_x1, *d_x2, *d_x3, *d_input, *d_s;

    // Allocate memory on the GPU
    cudaMalloc((void **)&d_x1, sizeof(int));
    cudaMalloc((void **)&d_x2, sizeof(int));
    cudaMalloc((void **)&d_x3, sizeof(int));
    cudaMalloc((void **)&d_input, sizeof(int) * 10);
    cudaMalloc((void **)&d_s, sizeof(int));

    // Copy input data from host to device
    cudaMemcpy(d_input, &input, sizeof(int) * 10, cudaMemcpyHostToDevice);
    cudaMemcpy(d_s, &s, sizeof(int), cudaMemcpyHostToDevice);

    // Launch the kernel
    sort<<<1, 10>>>(d_x1, d_x2, d_x3, d_input, *d_s);

    // Copy result from device to host
    cudaMemcpy(&x1, d_x1, sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(&x2, d_x2, sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(&x3, d_x3, sizeof(int), cudaMemcpyDeviceToHost);

    // Free memory
    cudaFree(d_x1);
    cudaFree(d_x2);
    cudaFree(d_x3);
    cudaFree(d_input);
    cudaFree(d_s);

    printf("%d\n%d\n%d\n", x1, x2, x3);
    return 0;
}