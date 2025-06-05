__global__ void add(x_t *x, y_t *y) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if (tid < 9) {
        x[tid] += y[tid];
    }
}