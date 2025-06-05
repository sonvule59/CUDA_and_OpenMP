#include <stdio.h>
int s,e;
__global__ void kernel(int *s, int *e) {
    while(s*e<81)s+=(e=e%9+1)<2;
}
int main() {
    int s, e;
    int *d_s, *d_e;
    cudaMalloc((void **)&d_s, sizeof(int));
    cudaMalloc((void **)&d_e, sizeof(int));
    cudaMemcpy(d_s, &s, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_e, &e, sizeof(int), cudaMemcpyHostToDevice);
    kernel<<<1,1>>>(d_s, d_e);
    cudaMemcpy(&s, d_s, sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(&e, d_e, sizeof(int), cudaMemcpyDeviceToHost);
    printf("%d x %d = %d\n", s, e, s*e);
    cudaFree(d_s);
    cudaFree(d_e);
    return 0;
}