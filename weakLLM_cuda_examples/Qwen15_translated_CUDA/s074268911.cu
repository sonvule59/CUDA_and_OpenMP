__global__ void my_kernel(int n, int *s, int *g) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        s[i] = g * i;
    }
}