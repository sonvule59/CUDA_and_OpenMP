__global__ void multiThreadedKernel(int* A, int* B, int N) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if (tid < N)
    {
        int index = tid * blockDim.x + threadIdx.y;
        int value = A[index] * B[index];
        // Store the result in a device memory location
        cudaMemcpy(&result, &value, sizeof(int), cudaMemcpyDeviceToHost);
        // Update the global counter
        globalCounter += value;
    }
}