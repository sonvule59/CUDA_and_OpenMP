__global__ void multiply(int *A, int *B, int *C) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    
    if (i < A.size() && j < B.size()) {
        C[i] = A[i] * B[j];
    }
}