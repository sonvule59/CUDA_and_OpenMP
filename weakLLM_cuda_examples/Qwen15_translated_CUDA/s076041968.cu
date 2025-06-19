__global__ void multiplyKernel(int* a, int* b, int c) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if (tid < 1 || tid >= 10) {
        return;
    }

    int rowA = a[tid];
    int colB = b[tid];

    // Perform multiplication on rowA and columnB
    int product = rowA * colB;

    // Store the result in the local memory
    c[tid] = product;
}