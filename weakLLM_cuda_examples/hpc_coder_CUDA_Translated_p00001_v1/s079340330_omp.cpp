#include <stdio.h>

__global__ void sort(int *a, int *b) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < 10) {
        int temp = a[idx];
        int i = idx;
        while (i > 0 && a[i - 1] < temp) {
            a[i] = a[i - 1];
            i--;
        }
        a[i] = temp;
    }
}

int main() {
    int a[10], b[3] = {0, 0, 0};
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    int *d_a, *d_b;
    cudaMalloc((void **)&d_a, 10 * sizeof(int));
    cudaMalloc((void **)&d_b, 3 * sizeof(int));
    cudaMemcpy(d_a, a, 10 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, 3 * sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1, 10>>>(d_a, d_b);
    cudaMemcpy(b, d_b, 3 * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_a);
    cudaFree(d_b);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", b[i]);
    }
    return 0;
}