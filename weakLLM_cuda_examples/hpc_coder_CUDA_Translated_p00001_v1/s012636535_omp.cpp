#include <stdio.h>

__global__ void sort(int *h, int *a, int *b, int *c) {
    int i = threadIdx.x;
    if (i < 10) {
        if (h[i] > *c) {
            *c = h[i];
            if (*c > *b) {
                int temp = *b;
                *b = *c;
                *c = temp;
                if (*b > *a) {
                    temp = *a;
                    *a = *b;
                    *b = temp;
                }
            }
        }
    }
}

int main() {
    int h[10], a = 0, b = 0, c = 0, temp;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &h[i]);
        if (h[i] < 0 || h[i] > 10000)
            i--;
    }

    int *d_h, *d_a, *d_b, *d_c;
    cudaMalloc((void **)&d_h, 10 * sizeof(int));
    cudaMalloc((void **)&d_a, sizeof(int));
    cudaMalloc((void **)&d_b, sizeof(int));
    cudaMalloc((void **)&d_c, sizeof(int));

    cudaMemcpy(d_h, h, 10 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_a, &a, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, &c, sizeof(int), cudaMemcpyHostToDevice);

    sort<<<1, 10>>>(d_h, d_a, d_b, d_c);

    cudaMemcpy(&a, d_a, sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(&b, d_b, sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(&c, d_c, sizeof(int), cudaMemcpyDeviceToHost);

    printf("%d\n%d\n%d\n", a, b, c);

    cudaFree(d_h);
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}