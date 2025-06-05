__global__ void main() {
    int i = blockIdx.x * blockDim.x + threadIdx.x; // Global block index
    int k = blockIdx.y * blockDim.y + threadIdx.y; // Global block index

    if (i >= 0 && i < 9 && k >= 0 && k < 9) { // Check if block indices are within range
        int x = i + 1; // Row index
        int y = k + 1; // Column index

        // Calculate element-wise product of row and column indices
        int product = x * y;

        // Store the product in a device variable
        int result = threadIdx.x + threadIdx.y * blockDim.x;
        __syncthreads();

        // Write the product to a host memory location
        hostMemory[product] = result;

        // Update the thread index
        threadIdx.x += blockDim.x * gridDim.x;
        threadIdx.y += blockDim.y * gridDim.y;
    }

    // Print the product on the host side
    printHostResult(result);
}