__global__ void matrixMultiplicationKernel(float* A, float* B, int N, float* C) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;

    if (row >= N && col >= N) {
        float sum = 0.0f;
        
        // Loop over each element of A and B
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                sum += A[i] * B[j];
            }
        }

        // Store the result in C
        C[row * N + col] = sum;
    }
}