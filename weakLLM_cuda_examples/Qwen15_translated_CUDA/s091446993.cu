#include <cuda_runtime.h>

__global__ void my_kernel(float* A, float* B, int N) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if(tid < N) {
        float sum = 0.0f;
        for(int i = tid; i < N; i += blockDim.x * gridDim.x) {
            sum += A[i] * B[tid];
        }
        printf("Sum at thread %d: %f\n", tid, sum);
    }
}

int main(int argc, char const *argv[]) {
    // Load the input data into GPU memory
    float* A = (float*)malloc(N * sizeof(float));
    VINT(A,N);
    
    // Create a kernel function that performs the multiplication operation on A and B
    float* B = (float*)malloc(N * sizeof(float));
    VINT(B,N);
    my_kernel<<<1,1>>>(A,B,N);

    // Copy the output data back to host memory
    cudaMemcpy(B,A,N * sizeof(float), cudaMemcpyHostToDevice);

    // Launch the kernel on the GPU
    int num_blocks = 5;
    int blocks_per_grid = 2;
    int grid_size = N / num_blocks;
    int threads_per_block = blockDim.x * grid_size;
    int device_size = grid_size * blockDim.x * blockDim.x;
    int num_threads = num_blocks * threads_per_block;
    int block_start = blockDim.x * blockIdx.x + threadIdx.x;
    int block_end = blockDim.x * blockIdx.x + blockDim.x * blockDim.x * num_threads - threads_per_block;
    my_kernel<<<block_start,block_end,num_threads>>>(B,A,N);

    // Read the result from host memory
    float* result = (float*)malloc(N * sizeof(float));
    VINT(result,N);
    cudaMemcpy(result,B,N * sizeof(float), cudaMemcpyDeviceToHost);

    // Print the result
    for(int i = 0; i < N; i++) {
        printf("Result at thread %d: %f\n", i, result[i]);
    }

    free(A);
    free(B);
    free(result);

    return 0;
}