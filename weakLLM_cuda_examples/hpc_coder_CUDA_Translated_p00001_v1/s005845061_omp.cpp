c++
#include <stdio.h>

__global__ void sort(int *a, int n) {
    int tid = threadIdx.x;
    int i = tid;
    int tmp;
    while (i < n) {
        tmp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
        i += blockDim.x * gridDim.x;
    }
}

int main() {
    int a[10] = {0};
    int n = 10;
    int *d_a;
    cudaMalloc((void **)&d_a, n * sizeof(int));
    cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1, n>>>(d_a, n);
    cudaMemcpy(a, d_a, n * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_a);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}