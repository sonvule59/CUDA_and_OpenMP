#include <cuda_runtime.h>

__global__ void matrixMultiplicationKernel(float* A, float* B, int M, int N) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;

    if (row >= M && col >= N) {
        float sum = 0;
        
        for (int k = 0; k < N; k++) {
            sum += A[row * N + k] * B[col * M + k];
        }

        cudaMemcpy(&sum, A + row * M * N, sizeof(float), cudaMemcpyDeviceToHost);
        
        // Store the result back on host side
        A[row * N + col] = sum;
    }
}

int main() {
    #pragma unroll loop(2)
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 1; j <= 9; j += 2) {
            float A[10][10], B[10][10];

            // Copy data from CPU to GPU
            cudaMemcpy(A, &i * j, sizeof(float), cudaMemcpyDeviceToHost);

            // Launch kernel
            matrixMultiplicationKernel<<<1, 1>>>(A, B, 10, 10);

            // Copy the result back to CPU
            cudaMemcpy(B, A, sizeof(float), cudaMemcpyDeviceToHost);
        }
    }

    return 0;
}