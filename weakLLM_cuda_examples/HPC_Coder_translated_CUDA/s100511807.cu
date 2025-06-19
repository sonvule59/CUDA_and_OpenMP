#include <stdio.h>
int s,e;
__global__ void kernel(int *s, int *e) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < 10) {
        s[idx] = (e[idx] = e[idx] % 9 + 1) < 2 ? s[idx] : 0;
        printf("%d x %d = %d\n", s[idx], e[idx], s[idx] * e[idx]);
    }
}
int main() {
    int s[10], e[10];
    for (int i = 0; i < 10; i++) {
        s[i] = 0;
        e[i] = i;
    }
    int *d_s, *d_e;
    cudaMalloc((void **)&d_s, 10 * sizeof(int));
    cudaMalloc((void **)&d_e, 10 * sizeof(int));
    cudaMemcpy(d_s, s, 10 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_e, e, 10 * sizeof(int), cudaMemcpyHostToDevice);
    kernel<<<1, 10>>>(d_s, d_e);
    cudaMemcpy(s, d_s, 10 * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_s);
    cudaFree(d_e);
    return 0;
}