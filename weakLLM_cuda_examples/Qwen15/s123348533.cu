#include <cuda_runtime.h>

__global__ void matrix multiplication_kernel(float* A, float* B, float* C, int m, int n) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;

    if(row >= m && col >= n) {
        float sum = 0.0f;
        for(int k = 0; k < n; k++) {
            sum += A[row*m+k] * B[col*n+k];
        }

        C[row*m+col] = sum;
    }
}

int main() {
    // Initialize CUDA runtime
    cudaRuntimeInit();

    // Allocate memory for input matrices A and B
    float* A = (float*)malloc(sizeof(float)*m);
    float* B = (float*)malloc(sizeof(float)*n);

    // Copy input matrices to CUDA memory
    cudaMemcpy(A, &A[m], sizeof(float)*m, cudaMemcpyHostToDevice);
    cudaMemcpy(B, &B[n], sizeof(float)*n, cudaMemcpyHostToDevice);

    // Set block size and grid size
    int blockDimX = 32;
    int blockDimY = 32;
    int numBlocks = ceil(m / blockDimX) + ceil(n / blockDimY);

    // Create a kernel function for matrix multiplication
    matrix multiplication_kernel<<<numBlocks, blockDimX, blockDimY>>>(A, B, C, m, n);

    // Launch kernel on GPU
    int threads_per_block = blockDim.x * blockDim.y;
    int grid_size = blockDimX * blockDimY;
    int num_threads = threads_per_block * numBlocks;
    cudaDeviceProp prop;
    cudaGetDeviceProperties(&prop, 0);
    cudaGetDeviceID(prop.major, prop.minor, 0);

    // Create a CUDA context
    cudaContextCreate(&context);

    // Launch kernel on GPU with device context
    cudaLaunchKernel(multiplication_kernel, num_threads, grid_size, threads_per_block, A, B, C, &context);

    // Free memory allocated for input matrices
    free(A);
    free(B);

    // Clean up CUDA resources
    cudaDeviceSynchronize();
    cudaFree(context);

    return 0;
}