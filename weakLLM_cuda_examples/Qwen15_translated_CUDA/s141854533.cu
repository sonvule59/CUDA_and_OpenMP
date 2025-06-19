__global__ void addSum(int* a, int* b, int* c) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if (tid < 10) {
        c[tid] = a[tid] + b[tid];
    }
}