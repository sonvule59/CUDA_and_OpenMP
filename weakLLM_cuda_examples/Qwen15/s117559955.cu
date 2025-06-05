__global__ void matrix multiplicationKernel(float* A, float* B, float* C, int m, int n) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;

    if(row >= m && col >= n) {
        float sum = 0;
        for(int k = 0; k < n; k++) {
            sum += A[row*m+k] * B[col*n+k];
        }

        C[row*m+n] = sum;
    }
}