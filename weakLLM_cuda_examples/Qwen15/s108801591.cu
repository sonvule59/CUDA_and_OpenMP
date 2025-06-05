__global__ void kernel(int x, int y) {
    int sum = 0;
    
    for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < blockDim.x * gridDim.x; i += blockDim.x * blockDim.y) {
        sum += x * y;
    }
    
    // Store the result in a device variable
    __shared__ int sharedSum __device__(align(64));
    sharedSum[0] = sum;
    
    // Write the result back to host memory
    cudaMemcpy(hostSum, sharedSum, sizeof(int), cudaMemcpyDeviceToHost);
    
    // Print the result
    std::cout << "Sum of " << x << "x" << y << " on GPU: " << hostSum << std::endl;
}