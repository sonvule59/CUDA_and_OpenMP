c++
#include<cstdio>

__global__ void sort(int *h, int n) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < n) {
        for (int j = i + 1; j < n; j++) {
            if (h[i] < h[j]) {
                int box = h[j];
                h[j] = h[i];
                h[i] = box;
            }
        }
    }
}

int main() {
    int h[10];
    for(int i=0;i<10;i++)scanf("%d",&h[i]);

    int *d_h;
    cudaMalloc((void **)&d_h, 10 * sizeof(int));
    cudaMemcpy(d_h, h, 10 * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
    sort<<<blocksPerGrid, threadsPerBlock>>>(d_h, 10);

    cudaMemcpy(h, d_h, 10 * sizeof(int), cudaMemcpyDeviceToHost);

    for(int i=0;i<3;i++)printf("%d\n",h[i]);
    return 0;
}