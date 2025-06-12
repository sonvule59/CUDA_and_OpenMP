#include <stdio.h>

__global__ void sort(int *a) {
    int i = threadIdx.x;
    int temp;
    for (int j = 0; j < 10 - 1; j++) {
        if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    int *d_a;
    cudaMalloc((void **)&d_a, 10 * sizeof(int));
    cudaMemcpy(d_a, a, 10 * sizeof(int), cudaMemcpyHostToDevice);

    sort<<<1, 10>>>(d_a);

    cudaMemcpy(a, d_a, 10 * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < 3; i++) {
        printf("%d\n", a[i]);
    }

    cudaFree(d_a);
    return 0;
}