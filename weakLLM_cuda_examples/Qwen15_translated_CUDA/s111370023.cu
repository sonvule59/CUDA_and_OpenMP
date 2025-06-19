__global__ void main() {
    int i = blockIdx.x * blockDim.x + threadIdx.x; // Global block size and thread index
    int k = blockIdx.y * blockDim.y + threadIdx.y; // Global block size and thread index

    if (i <= 8 && k <= 8) { // Check if block is within range of threads
        for (int j = 1; j <= 9; j++) {
            float x = i * j; // Calculate element on local grid
            float y = k * j; // Calculate element on local grid
            printf("x%d y%d = %f\n", j, j, x * y); // Print element on local grid
        }
    }
}