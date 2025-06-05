__global__ void matrix_multiplication(int m, int n, int *A, int *B, int *C) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < m && i < n) {
        int sum = 0;
        
        for (int j = 0; j < n; j++) {
            sum += A[i] * B[j];
        }
        
        C[i] = sum;
    }
}