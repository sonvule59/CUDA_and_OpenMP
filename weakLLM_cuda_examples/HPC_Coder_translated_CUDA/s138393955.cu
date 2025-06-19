#include <stdio.h>

__global__ void print_table(int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    if (i < n && j < n) {
        int n1 = i + 1;
        int n2 = j + 1;
        printf("%d x %d = %d\n", n1, n2, n1 * n2);
    }
}

int main() {
    int n = 9;
    int threadsPerBlock = 16;
    int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;

    print_table<<<blocksPerGrid, threadsPerBlock>>>(n);

    cudaDeviceSynchronize();

    return 0;
}