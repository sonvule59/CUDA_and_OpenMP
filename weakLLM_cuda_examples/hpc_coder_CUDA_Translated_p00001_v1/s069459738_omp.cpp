#include <stdio.h>

__global__ void sort(int *height, int n) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < n) {
        for (int j = n - 1; j > i; j--) {
            if (height[j] > height[j - 1]) {
                int tmp = height[j];
                height[j] = height[j - 1];
                height[j - 1] = tmp;
            }
        }
    }
}

int main() {
    int height[10];
    int n = 10;

    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int *d_height;
    cudaMalloc((void **)&d_height, n * sizeof(int));
    cudaMemcpy(d_height, height, n * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
    sort<<<blocksPerGrid, threadsPerBlock>>>(d_height, n);

    cudaMemcpy(height, d_height, n * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < 3; i++) {
        printf("%d\n", height[i]);
    }

    cudaFree(d_height);
    return 0;
}