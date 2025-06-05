__global__ void multKernel(int *A, int *B, int N, int M) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    if (i < N && j < M) {
        A[i] *= B[j];
    }
}