#include <stdio.h>

__global__ void print_table(int start, int end) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx >= start && idx <= end) {
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", idx, i, idx * i);
        }
    }
}

int main() {
    int start = 1;
    int end = 9;
    int threadsPerBlock = 256;
    int blocksPerGrid = (end - start + 1 + threadsPerBlock - 1) / threadsPerBlock;
    print_table<<<blocksPerGrid, threadsPerBlock>>>(start, end);
    cudaDeviceSynchronize();
    return 0;
}