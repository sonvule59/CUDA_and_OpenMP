#include <stdio.h>

__global__ void kernel(int *x, int *y, int *z) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < 10) {
        for (int i = 0; i < 10; i++) {
            *x = *x + 1;
            *y = *x * *z;
            printf("%d x %d = %d\n", *x, *z, *y);
            *z = *z + 1;
            if (*z >= 9) {
                break;
            }
        }
        *z = 0;
    }
}

int main() {
    int x, y, z;
    x = 0;
    y = 0;
    z = 0;
    int *d_x, *d_y, *d_z;
    cudaMalloc((void **)&d_x, sizeof(int));
    cudaMalloc((void **)&d_y, sizeof(int));
    cudaMalloc((void **)&d_z, sizeof(int));
    cudaMemcpy(d_x, &x, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, &y, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_z, &z, sizeof(int), cudaMemcpyHostToDevice);
    kernel<<<1, 10>>>(d_x, d_y, d_z);
    cudaMemcpy(&x, d_x, sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(&y, d_y, sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(&z, d_z, sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_x);
    cudaFree(d_y);
    cudaFree(d_z);
    return 0;
}