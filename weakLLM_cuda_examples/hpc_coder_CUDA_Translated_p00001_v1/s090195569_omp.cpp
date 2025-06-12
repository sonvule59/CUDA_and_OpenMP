#include <stdio.h>

__global__ void sort(int *hM, int n) {
    int i = threadIdx.x;
    int temp;

    for (int k = 0; k < n - 1; k++) {
        if (hM[k] > hM[k + 1]) {
            temp = hM[k];
            hM[k] = hM[k + 1];
            hM[k + 1] = temp;
        }
    }
}

int main() {
    int hM[10], I, K, temp;

    for(I = 0; I < 10; I = I + 1)
        scanf("%d", &hM[I]);

    int *d_hM;
    cudaMalloc((void **)&d_hM, 10 * sizeof(int));
    cudaMemcpy(d_hM, hM, 10 * sizeof(int), cudaMemcpyHostToDevice);

    sort<<<1, 10>>>(d_hM, 10);

    cudaMemcpy(hM, d_hM, 10 * sizeof(int), cudaMemcpyDeviceToHost);

    for(I = 0; I < 3; I = I + 1)
        printf("%d\n", hM[I]);

    cudaFree(d_hM);

    return 0;
}