__global__ void matrix multiplication_kernel(float *A, float *B, int N, int M) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;

    if (row >= N && col >= M) {
        float sum = 0.0f;
        
        // Access elements of A and B on grid threads
        for (int k = 0; k < N; k++) {
            for (int l = 0; l < M; l++) {
                sum += A[row * M + k] * B[l * N + col];
            }
        }

        // Store result in host memory
        A[row * M + col] = sum;
    }
}