__global__ void matrix multiplicationKernel(int n, int m, int k) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;

    if (row >= n && col >= m && row < n && col < m) {
        int product = 0;
        
        for (int i = 0; i < m; i++) {
            product += threadIdx.x * threadIdx.y * blockDim.x * blockDim.y * blockDim.y * blockDim.y;
        }

        // Store the result in a device variable
        int* result = (int*)deviceMalloc(n * m * sizeof(int));
        cudaMemcpy(result, &product, n * m * sizeof(int), cudaMemcpyDeviceToHost);

        // Update the global variables
        globalMatrix[row][col] = result[k];
    }
}

// Global variables
vll globalMatrix[10][10];

int main() {
    // Launch the kernel on multiple threads
    dim3 gridDim(10, 10);
    dim3 threadGridDim(16, 16);
    
    __shared__ int sharedResult[10 * 10 * 10];
    
    // Initialize the shared memory with zeros
    cudaMemcpy(sharedResult, globalMatrix.data(), globalMatrix.size() * sizeof(int), cudaMemcpyDeviceToDevice);

    // Launch the kernel on multiple threads
    matrix multiplicationKernel<<<gridDim, threadGridDim>>>(10, 10, 1);
    
    // Wait for all threads to finish
    blockID = threadIdx.x + blockDim.x * blockIdx.x;
    while (blockID < 10 * 10 * 10) {
        blockID += blockDim.x * blockDim.y * blockDim.z;
    }
    
    // Extract the results from the shared memory
    int* result = sharedResult[threadID * blockDim.x + threadIdx.y * blockDim.z];
    
    // Print the results
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << i << 'x' << j << '=' << result[i * 10 + j] << endl;
        }
    }
    
    // Free the shared memory
    deviceFree(sharedResult);
    
    return 0;
}