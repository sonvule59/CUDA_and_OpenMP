__global__ void add(int* A, int* B, int* C, int N) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if (tid < N) {
        int sum = 0;
        for (int i = 0; i < N; i += blockDim.x * gridDim.x) {
            sum += A[tid] + B[tid];
        }
        C[tid] = sum;
    }
}