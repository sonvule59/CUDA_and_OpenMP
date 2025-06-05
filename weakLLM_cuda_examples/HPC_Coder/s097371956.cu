#include <stdio.h>
#define N 9

__global__ void print_multiplication_table(int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    if (i <= N && j <= N) {
        printf("%dx%d=%d\n", i, j, i*j);
    }
}

int main() {
    int N = 9;
    int threadsPerBlock = 16;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    print_multiplication_table<<<blocksPerGrid, threadsPerBlock>>>(N);

    return 0;
}