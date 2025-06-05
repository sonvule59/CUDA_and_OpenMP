__global__ void matrix_multiplication_kernel(float* A, float* B, int m, int n, float* C) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < m && i < n) {
        float sum = 0.0f;
        
        for (int j = 0; j < n; ++j) {
            sum += A[i*m+j] * B[j];
        }
        
        C[i*m+n] = sum;
    }
}